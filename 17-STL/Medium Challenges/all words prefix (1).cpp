#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {

    int N;
    string input, prefix_name;
    cin >> N;
    map<string, vector<string>> mp;
    while (N-- > 0) {
        cin >> input;
        prefix_name = "";
        for (char ch : input) {
            prefix_name += ch;
            mp[prefix_name].push_back(input);
        }
    }
    cin >> N;
    while (N-- > 0) {
        cin >> input;
        for (string name : mp[input])
            cout << name << " ";
        cout << endl;
    }
    return 0;
}

/*
4

mostafa
morad
nawal
marwa

4

m 
mo
mos
naw
*/
