#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
struct Session {
	string id;
	string name;
	bool allow_anonymous = false;

	void logout() {
		id = "";
		name = "";
		allow_anonymous = false;
	}
};

struct UserManager {
	ifstream fin;
	ofstream fout;


	UserManager() {
		fin.open("users.txt");
		fout.open("users.txt", ios::app);

		if (fin.fail() || fout.fail())
			cerr << "Failed to open users.txt for writing.\n" << endl;
	}

	~UserManager() {
		if (fin.is_open())
			fin.close();
		if (fout.is_open())
			fout.close();
	}

	bool is_anonymous(const string& id) {
		string line, field;
		reset_and_begin();
		bool anonymous = false;
		while (getline(fin, line)) {
			istringstream iss(line);
			getline(iss, field, ',');
			if (field == id) {
				getline(iss, field, ',');
				getline(iss, field, ',');
				getline(iss, field, ',');
				getline(iss, field, ',');
				iss >> anonymous;
				break;
			}
		}
		return anonymous;
	}

	void login(Session& current_session, int tries = 3) {
		string user_name, password;

		for (int attempt = 0; attempt < tries; attempt++) {
			cout << "Enter user name & password: ";
			cin >> user_name >> password;

			if (already_exist(user_name, true, current_session, password)) {
				return; // Successful login, exit function
			}

			if (attempt < tries - 1) { // Not the last attempt
				cout << "Invalid credentials. Please try again." << endl;
			}
		}

		// All attempts failed
		cout << "All login attempts failed. Please create a new account." << endl;
		cout << "################# SIGNUP #############################" << endl;
		signup(current_session);
	}

	void list_system_users() {
		reset_and_begin();
		string line, field;
		while (getline(fin, line)) {
			istringstream iss(line);
			if (!getline(iss, field, ',')) continue;
			cout << "ID: " << field;

			getline(iss, field, ',');
			getline(iss, field, ',');
			getline(iss, field, ',');

			cout << "          NAME: " << field << endl;
		}

	}

	void logout(Session& current_session) {
		current_session.logout();
		cout << "Logout successful" << endl;
	}

	bool already_exist(const string& user_name, bool check_password, Session& current_session, const string& u_password = "") {
		reset_and_begin();
		string line, id, username, password, name, email;
		bool anonymous;

		while (getline(fin, line)) {
			istringstream iss(line);

			getline(iss, id, ',');
			getline(iss, username, ',');
			getline(iss, password, ',');
			getline(iss, name, ',');
			getline(iss, email, ',');
			iss >> anonymous;

			if (username != user_name) continue;

			// If only checking username, return immediately
			if (!check_password) {
				current_session.id = id;
				current_session.name = name;
				current_session.allow_anonymous = anonymous;
				return true;
			}

			if (password == u_password) {
				current_session.id = id;
				current_session.name = name;
				current_session.allow_anonymous = anonymous;
				cout << "Login successful. Welcome, " << current_session.name << "!\n";
				return true;
			};
		}
		return false;
	}

	void signup(Session& current_session) {
		string user_name, password, email, name;
		bool anonymous;

		string username;
		cout << "Enter user name. (No spaces): ";
		cin >> username;
		if (already_exist(username, false, current_session)) {
			cout << "that user name already exists !" << endl;
			login(current_session);
			return;
		}

		cout << "Enter password: ";
		cin >> password;

		cout << "Enter name: ";
		cin >> name;

		cout << "Enter email: ";
		cin >> email;


		cout << "Allow anonymous questions?: (0 or 1): ";
		cin >> anonymous;

		cout << endl;

		int id = generate_user_id();
		fout << id << "," << username << "," << password << "," << email << "," << name << "," << anonymous << endl;

		current_session.id = id;
		current_session.name = name;
		current_session.allow_anonymous = anonymous;

		cout << "Signup successful. Welcome, " << current_session.name << "!\n";

	}

	void reset_and_begin() {
		fin.clear();
		fin.seekg(0);
	}

	int generate_user_id() {
		reset_and_begin();
		string line;
		int max_id = -1;

		while (getline(fin, line)) {
			istringstream iss(line);
			string id_str;
			if (getline(iss, id_str, ',')) {
				int current_id = stoi(id_str);
				max_id = max(max_id, current_id);
			}
		}
		return (max_id == -1) ? 0 : max_id + 1;
	}

};


struct Questions {
	ifstream fin;
	ofstream fout;
	int id, from, to;

	Questions() {
		fin.open("questions.txt");
		fout.open("questions.txt", ios::app);

		if (fin.fail() || fout.fail())
			cerr << "Failed to open questions.txt for writing.\n" << endl;

		id = from = to = -1;
	}

	~Questions() {
		if (fin.is_open())
			fin.close();
		if (fout.is_open())
			fout.close();
	}

	void print_questions_to_me(Session& current_session, UserManager& user) {
		reset_and_begin();
		vector<string> v;
		string line, id, from_id, to_id, question;
		while (getline(fin, line)) {
			bool thread = false;
			string answer = "";
			istringstream iss(line);
			getline(iss, id, ',');
			if (id == "-2") {
				if (!v.empty()) v.pop_back();
				v.push_back(line);
				getline(iss, id, ',');
			}
			else if (id == "-1")
				getline(iss, id, ','), thread = true;
			getline(iss, from_id, ',');
			getline(iss, to_id, ',');
			getline(iss, question, ',');
			getline(iss, answer, ',');

			if (to_id == current_session.id) {
				if (!v.empty() && thread) {
					istringstream iss_temp(v.front());
					v.pop_back();
					string parent_id, parent_from, parent_to, parent_question, parent_answer = "";
					getline(iss_temp, parent_id, ',');
					getline(iss_temp, parent_id, ',');
					getline(iss_temp, parent_from, ',');
					getline(iss_temp, parent_to, ',');
					getline(iss_temp, parent_question, ',');
					getline(iss_temp, parent_answer, ',');
					cout << "Parent Question: ";
					cout << "Question Id (" << parent_id << ")";
					if (!user.is_anonymous(current_session.id) || user.is_anonymous(parent_from))
						cout << " from user id (" << parent_from << ")";
					cout << "             Question: " << parent_question << endl;
					if (parent_answer.length() > 0) {
						cout << "    Answer: " << parent_answer << endl;
					}
				}
				if (thread)	cout << "	Thread: ";
				cout << "Question Id (" << id << ")";
				if (!user.is_anonymous(current_session.id) || user.is_anonymous(from_id))
					cout << " from user id (" << from_id << ")";
				cout << "             Question: " << question << endl;
				if (answer.length() > 0) {
					cout << "    Answer: " << answer << endl;
				}
			}
		}
	}

	void print_questions_from_me(const Session& current_session, UserManager& user) {
		reset_and_begin();
		string id, from_id, to_id, question, line, answer;
		vector<string> v;
		while (getline(fin, line)) {
			bool thread = false;
			istringstream iss(line);
			getline(iss, id, ',');
			if (id == "-2") {
				if (!v.empty()) v.pop_back();
				v.push_back(line);
				continue;

			}
			else if (id == "-1") {
				getline(iss, id, ',');
				thread = true;
			}
			getline(iss, from_id, ',');
			if (from_id == current_session.id) {
				if (!v.empty() && thread) {
					istringstream iss_temp(v.front());
					string parent_id;
					v.pop_back();
					getline(iss_temp, parent_id, ',');
					getline(iss_temp, parent_id, ',');
					getline(iss_temp, from_id, ',');
					getline(iss_temp, to_id, ',');
					getline(iss_temp, question, ',');
					getline(iss_temp, answer, ',');
					cout << "Parent Question: ";
					cout << "Question Id (" << parent_id << ")";
					cout << (user.is_anonymous(to_id) ? "" : " !AQ ");
					cout << "to user id (" << to_id << ")";
					cout << "             Question: " << question << endl;
					if (answer.length() > 0) {
						cout << "    Answer: " << answer << endl;
						answer = "";
					}
				}
				getline(iss, to_id, ',');
				getline(iss, question, ',');
				getline(iss, answer, ',');
				if (thread)	cout << "	Thread: ";
				cout << "Question Id (" << id << ")";
				cout << (user.is_anonymous(to_id) ? "" : " !AQ ");
				cout << "to user id (" << to_id << ")";
				cout << "             Question: " << question << endl;
				if (answer.length() > 0) {
					cout << "    Answer: " << answer << endl;
					answer = "";
				}
			}
		}
	}


	void delete_questions(Session& current_session) {
    int id;
    string line, q_id, user_id;
    vector<string> lines_to_keep;
    bool found_target = false;
    
    reset_and_begin();
    cout << "Enter Question id or -1 to cancel: ";
    cin >> id;
    if (id == -1)
        return;
    
    // Read all lines first
    while (getline(fin, line)) {
        istringstream iss(line);
        string current_q_id;
        getline(iss, current_q_id, ',');
        
        // Handle parent questions (-2) and threads (-1)
        bool is_parent = (current_q_id == "-2");
        bool is_thread = (current_q_id == "-1");
        
        if (is_parent || is_thread) {
            getline(iss, current_q_id, ','); // Get actual question ID
        }
        
        getline(iss, user_id, ',');
        
        // Check if this is the question to delete
        if (current_q_id == to_string(id) && user_id == current_session.id) {
            found_target = true;
            
            continue;
        }
        
        // If we found a parent question to delete, skip all following threads
        if (found_target && is_thread) {
            continue;
        }
        
        // If we reach here and it's not a thread after a deleted parent, reset found_target
        if (found_target && !is_thread && !is_parent) {
            found_target = false;
        }
        
        // Keep this line
        lines_to_keep.push_back(line);
    }
    
    fin.close();
    fout.close();
    
    // Rewrite the file
    ofstream temp("questions.txt");
    for (const string& kept_line : lines_to_keep) {
        temp << kept_line << endl;
    }
    temp.close();
    
    // Reopen files
    fin.open("questions.txt");
    fout.open("questions.txt", ios::app);
    if (fin.fail() || fout.fail()) {
        cerr << "Failed to open questions.txt for writing.\n" << endl;
    }
}

	void answer_question(Session current_session) {
		int id;
		string line, q_id, user_id, to_user_id, question, answer;
		ofstream temp("temp.txt");
		reset_and_begin();
		cout << "Enter Question id or -1 to cancel: ";
		cin >> id;
		if (id == -1)
			return;
		while (getline(fin, line)) {
			bool parent = false;
			bool thread = false;
			istringstream iss(line);
			getline(iss, q_id, ',');
			if (q_id == "-2") parent = true;
			else if (q_id == "-1") thread = true;
			if (q_id == "-1" || q_id == "-2") getline(iss, q_id, ',');

			getline(iss, user_id, ',');
			getline(iss, to_user_id, ',');
			if ((q_id == to_string(id)) && (to_user_id == current_session.id)) {
				getline(iss, question, ',');
				cout << "Question Id (" << id << ") from user id (" << user_id << ")";
				cout << "             Question: " << question << endl;
				if (!getline(iss, answer, ',')) {
					cout << "Enter the Answer: " << endl;
					cin.ignore();
					getline(cin, answer);
					temp << (thread ? "-1," : "") << (parent ? "-2," : "") << q_id << "," << user_id << "," << to_user_id << "," << question << "," << answer << endl;
				}
				else {
					cout << "Answer: " << answer << endl;
					cout << "Warning: Answer will be updated" << endl;
					cout << "Enter Answer: ";
					cin.ignore();
					getline(cin, answer);
					temp << (thread ? "-1," : "") << (parent ? "-2," : "") << q_id << "," << user_id << "," << to_user_id << "," << question << "," << answer << endl;
				}
				continue;
			}
			temp << line << endl;
		}
		fin.close();
		fout.close();
		temp.close();

		remove("questions.txt");
		rename("temp.txt", "questions.txt");

		fin.open("questions.txt");
		fout.open("questions.txt", ios::app);

		if (fin.fail() || fout.fail())
			cerr << "Failed to open questions.txt for writing.\n" << endl;
	}

	void reset_and_begin() {
		fin.clear();
		fin.seekg(0);
	}


	int generate_question_id() {
		reset_and_begin();
		string line;
		int max_id = -1;

		while (getline(fin, line)) {
			istringstream iss(line);
			string id_str;
			if (getline(iss, id_str, ',')) {
				if (id_str == "-1") getline(iss, id_str, ',');
				int current_id = stoi(id_str);
				max_id = max(max_id, current_id);
			}
		}
		return (max_id == -1) ? 100 : max_id + 1;
	}

	void ask_questions(Session& current_session, UserManager& user) {
		string question;
		int u_id, q_id;

		reset_and_begin();

		cout << "Enter user id or -1 to cancel: ";
		cin >> u_id;

		if (u_id == -1)
			return;

		if (!user.is_anonymous(to_string(u_id)))
			cout << "Note: Anonymous questions are not allowed for this user" << endl;

		cout << "For thread question: Enter Question id or -1 for new question: " << endl;
		cin >> q_id;
		cout << "Enter question text: ";
		cin.ignore();
		getline(cin, question);

		int id = generate_question_id();

		if (q_id == -1) {
			fout << id << "," << current_session.id << "," << u_id << "," << question << endl;
			fout.flush(); // Make sure it's written
		}
		else {
			// Close the streams temporarily
			fin.close();
			fout.close();

			// Work with temporary file
			ifstream original("questions.txt");
			ofstream temp("temp.txt");

			string line, question_id, from_user_id;

			while (getline(original, line)) {
				bool parent_q = false;
				istringstream iss(line);
				getline(iss, question_id, ',');
				if (question_id == "-2") getline(iss, question_id, ','), parent_q = true;
				if (question_id == "-1") getline(iss, question_id, ',');
				getline(iss, from_user_id, ',');

				if (to_string(q_id) == question_id && from_user_id == to_string(u_id)) {
					temp << ((parent_q) ? "" : "-2,") << line << endl;
					temp << -1 << "," << id << "," << current_session.id << "," << u_id << "," << question << endl;
				}
				if (!(to_string(q_id) == question_id && from_user_id == to_string(u_id)))
					temp << line << endl;
			}

			original.close();
			temp.close();

			remove("questions.txt");
			rename("temp.txt", "questions.txt");

			// Reopen the class streams
			fin.open("questions.txt");
			fout.open("questions.txt", ios::app);

			if (fin.fail() || fout.fail())
				cerr << "Failed to reopen questions.txt" << endl;
		}
	}

	void feed() {
		bool parent , thread;
		reset_and_begin();
		string question_id , from_id , to_id , question, answer , line;

		while (getline(fin, line)) {
			istringstream iss(line);
			if (!getline(iss, question_id, ',')) continue;
			parent = (question_id == "-2");
			thread = (question_id == "-1");
			if(question_id == "-2" || question_id == "-1") getline(iss , question_id , ',');
			getline(iss, from_id, ',');
			getline(iss, to_id, ',');
			getline(iss, question, ',');
			getline(iss, answer, ',');

			if(parent)	cout << "Parent: ";
			if(thread) 	cout << "Thread: ";
			
			cout << "Question Id (" << question_id << ")";
					cout << "from user id (" << from_id << ") ";
					cout << "to user id (" << to_id << ")";
					cout << "             Question: " << question << endl;
					if (answer.length() > 0) {
						cout << "    Answer: " << answer << endl;
						answer = "";
					}
		}
	}
};


struct AskMe {

	int menu_authentication() {
		int input;
		cout << "Menu: " << endl;
		cout << "        1:Login" << endl;
		cout << "        2:SignUp" << endl;
		cout << "        Enter number in range 1 - 2: ";
		cin >> input;

		while (input < 1 || input > 2) {
			cout << "Enter a valid number" << endl;
			cin >> input;
		}
		return input;
	}

	void menu_functionalities() {
		cout << "Menu:\n" << endl;
		cout << "1: Print Questions To Me" << endl;
		cout << "2: Print Questions From Me" << endl;
		cout << "3: Answer Question" << endl;
		cout << "4: Delete Question" << endl;
		cout << "5: Ask Question" << endl;
		cout << "6: List System Users" << endl;
		cout << "7: Feed" << endl;
		cout << "8: Logout" << endl;
	}

	void run() {
		UserManager user;
		Session current_session;
		Questions question;
		switch (menu_authentication()) {
		case 1:
			user.login(current_session);
			break;
		case 2:
			user.signup(current_session);
		}

		bool repeat = true;
		int input;
		menu_functionalities();
		while (repeat) {
			cout << "Enter number in range 1 - 8:";
			cin >> input;
			switch (input) {
			case 1:
				question.print_questions_to_me(current_session, user);
				break;
			case 2:
				question.print_questions_from_me(current_session, user);
				break;
			case 3:
				question.answer_question(current_session);
				break;
			case 4:
				question.delete_questions(current_session);
				break;
			case 5:
				question.ask_questions(current_session, user);
				break;
			case 6:
				user.list_system_users();
				break;
			case 7:
				question.feed();
				break;
			case 8:
			{
				user.logout(current_session);
				repeat = false;
			}
			break;
			default:
				cout << "ERROR: invalid number....Try again" << endl;
			}
		}
	}

};

int main() {
	AskMe v1;
	v1.run();

	return 0;
}

/*
2
AhmedEbeed
1111
Ahmed_Ebeed
aebeedcs@gmail.com
1

2
AnasEbeed
2222
Anas_Ebeed
anas@gmail.com
0

2
AsserEbeed
3333
Asser_Ebeed
asser@gmail.com
0

2
YassenEbeed
4444
Yaseen_Ebeed
yassen@gmail.com
1
*/

