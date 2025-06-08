#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
										// AskMe Project - version one 
struct Session {
	int id = -1;
	string name;
	bool allow_anonymous = false;

	void logout() {
		id = -1;
		name = "";
		allow_anonymous = false;
	}
};

struct Questions {
	ifstream fin;
	ofstream fout;
	int id, from, to;
	string content, answer;

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

	void print_questions_to_me(Session& current_session) {
		reset_and_begin();
		string line;
		while (getline(fin, line)) {
			istringstream iss(line);
			string field;
			getline(iss, field, ',');
			getline(iss, field, ',');
			getline(iss, field, ',');

			if (field == to_string(current_session.id)) {
				getline(iss, field, ',');
				cout << field << endl;
			}
		}
	}

	void print_questions_from_me(Session& current_session) {
		reset_and_begin();
		string line;
		while (getline(fin, line)) {
			istringstream iss(line);
			string field;
			getline(iss, field, ',');
			getline(iss, field, ',');

			if (field == to_string(current_session.id)) {
				getline(iss, field, ',');
				getline(iss, field, ',');
				cout << field << endl;
			}
		}
	}

	void delete_questions(Session& current_session) {
		int id;
		string line, q_id, user_id;
		ofstream temp("temp.txt");
		reset_and_begin();
		cout << "Enter Question id or -1 to cancel: ";
		cin >> id;
		if (id == -1)
			return;
		while (getline(fin, line)) {
			istringstream iss(line);
			getline(iss, q_id, ',');
			getline(iss, user_id, ',');
			if ((q_id == to_string(id)) && (user_id == to_string(current_session.id)))
				continue;
			temp << line << endl;
		}
		fin.close();
		fout.close();
		temp.close();

		remove("questions.txt");
		rename("temp.txt", "questions.txt");

		fin.open("questions.txt");
		fout.open("questions.txt", ios::app);
	}

	void answer_question(Session current_session) {
		int id;
		string line, q_id, user_id, to_user_id, question;
		ofstream temp("temp.txt");
		reset_and_begin();
		cout << "Enter Question id or -1 to cancel: ";
		cin >> id;
		if (id == -1)
			return;
		while (getline(fin, line)) {
			istringstream iss(line);
			getline(iss, q_id, ',');
			getline(iss, user_id, ',');
			if ((q_id == to_string(id)) && (user_id == to_string(current_session.id))) {
				getline(iss, to_user_id, ',');
				getline(iss, question, ',');
				cout << question << endl;

				cout << "Warning: question will be updated" << endl;
				cout << "Enter question: ";
				cin.ignore();
				getline(cin, question);
				temp << q_id << "," << user_id << "," << to_user_id << "," << question << endl;
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
				int current_id = stoi(id_str);
				max_id = max(max_id, current_id);
			}
		}
		return (max_id == -1)? 100 : max_id + 1;
	}

	void ask_questions(Session& current_session) {
		string question;
		int input;

		cout << "Enter user id or -1 to cancel: ";
		cin >> input;

		if (input == -1)
			return;
		cout << "Enter question text: ";
		cin.ignore();
		getline(cin, question);

		int id = generate_question_id();

		fout << id << "," << current_session.id << "," << input << "," << question << endl;
	}

	void feed() {
		reset_and_begin();
		string question, line;

		while (getline(fin, line)) {
			istringstream iss(line);
			if (!getline(iss, question, ',')) continue;
			getline(iss, question, ',');
			getline(iss, question, ',');
			getline(iss, question, ',');

			cout << question << endl;
		}
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
				current_session.id = stoi(id);
				current_session.name = name;
				current_session.allow_anonymous = anonymous;
				return true;
			}

			if (password == u_password) {
				current_session.id = stoi(id);
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
		return max_id + 1;
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
				question.print_questions_to_me(current_session);
				break;
			case 2:
				question.print_questions_from_me(current_session);
				break;
			case 3:
				question.answer_question(current_session);
				break;
			case 4:
				question.delete_questions(current_session);
				break;
			case 5:
				question.ask_questions(current_session);
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

