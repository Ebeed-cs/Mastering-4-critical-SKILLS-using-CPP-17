#include <iostream>
using namespace std;
/*
             Reverse a string

    ● Develop a function that do reverse for the string. Function is:
    ● string reverse_str(const string & str);
        ○ Don’t try to change str content or you will get compilation error
*/

string reverse_str(const string& str) {
    int len = str.length();
    string reversed_str {};
    for (int i = 0; i < len; ++i)
        reversed_str += str[len - 1 - i];
    return reversed_str;
}

int main() {
    string str;
    cin >> str;

    cout << reverse_str(str) << endl;
    return 0;
}
