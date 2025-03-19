#include <iostream>
using namespace std;

/*
                        Grouping

    ● Read a string, then divide it to consecutive groups of same letter. Print each group

    ● Input ⇒ outputs.
        ○ “111222aabbb” ⇒ 111 222 aa bbb
        ○ HHHH ⇒ HHHH

*/

int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(i && str[i] != str[i - 1]) 
            cout << " ";
        cout << str[i];
    }
    return 0;
}
