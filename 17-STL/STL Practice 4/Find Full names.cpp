#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	map<string, vector<string>> mp;

	cout << "Enter the number of names" << endl;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Number of strings in the full name and the strings" << endl;
		int num;
		cin >> num;

		string str;
		string full_name = "";
		vector<string> names;

		for (int j = 0; j < num; j++) {                 
			cin >> str;

			if (j)
				full_name += " ";

			full_name += str;
			names.push_back(full_name);
		}

		for (const auto &name : names)
			mp[name].push_back(full_name); // if found more than full_name to the same key will push for example : mostafa -> [mostafa saad ibrahim , mostafa saad ali , mostafa saad ibrahim mohamed] that which make us use a vector of strings not a normal string variable
	}

	cout << "Enter the number of queries" << endl;
	int num_queries;
	cin >> num_queries;

	for (int i = 0; i < num_queries; i++) {
		cout << "Number of strings in the full name and the strings to query" << endl;
		int num_strings;
		cin >> num_strings;

		string str;
		string full_name = "";

		for (int j = 0; j < num_strings; j++) {
			cin >> str;

			if (j)
				full_name += " ";

			full_name += str;
		}

		auto itr = mp.find(full_name);

		if (itr != mp.end()) {
			vector<string> names = itr->second;

			for (const auto &name : names)
				cout << name << endl;
		} else
			cout << "No such name exits " << endl;
	}
	return 0;
}



