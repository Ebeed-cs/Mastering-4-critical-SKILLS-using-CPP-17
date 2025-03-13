#include <iostream>
using namespace std;

/*
                        Is Suffix?
    ● Read 2 strings input and str. Print YES if the given str is a suffix for the string.
                    Otherwise, print NO

    ● Input ⇒ Outputs
        ○ ABCDEFG ABCD ⇒ NO
        ○ ABCDEFG ABCDEF ⇒ NO
        ○ ABCDEFG EFG ⇒ YES
        ○ ABCDEFG DEFG ⇒ YES
        ○ ABCDEFG BCD ⇒ NO
        ○ ABCDEFG DEF ⇒ NO
        ○ ABCDEFG ACEG ⇒ NO
        ○ ABCDEFG DG ⇒ NO
        ○ ABCDEFG GD ⇒ NO
        ○ ABCDEFG ABCDEFG ⇒ YES

*/

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO" << endl;
        return 0;
    }

    int size_str = str.size();
    int size_input = input.size();

    while(size_str){
        if(input[--size_input] != str[--size_str]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
