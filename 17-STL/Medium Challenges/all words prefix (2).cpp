#include <iostream>
#include <set>
#include <map>
using namespace std;

/*
                    all words prefix (2)

                    ● Given N, read N (!unique) strings. Then Read Q queries, for each query: print all strings that start with this prefix.Print them ordered no duplicate.
                    ● 5
                        ○ mostafa
                        ○ morad
                        ○ nawal
                        ○ marwa
                        ○ mostafa
                    ● 4
                        ○ m => [marwa morad mostafa]
                        ○ mo => [morad mostafa]
                        ○ mos => [mostafa]
                        ○ naw => [nawal]

*/

int main() {

    int N;
    string input, prefix_name;
    cin >> N;
    map<string, set<string>> mp;
    while (N-- > 0) {
        cin >> input;
        prefix_name = "";
        for (char ch : input) {
            prefix_name += ch;
            mp[prefix_name].insert(input);
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
5

mostafa
morad
nawal
marwa
mostafa

4

m 
mo
mos
naw
*/
