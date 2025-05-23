#include <iostream>
#include <vector>
#include <map>
using namespace std;

/*
                    all words prefix (1)

            ● Given N, read N unique strings. Then Read Q queries, for each query: print all strings that start with this prefix. Print use input order.Use a map
            ● 4
                ○ mostafa
                ○ morad
                ○ nawal
                ○ marwa
            ● 4
                ○ m => [mostafa morad marwa]
                ○ mo => [mostafa morad]
                ○ mos => [mostafa]
                ○ naw => [nawal]

*/

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
