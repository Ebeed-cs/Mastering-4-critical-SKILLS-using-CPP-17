#include <iostream>
using namespace std;

/*
                        Is Substring?

    ● Read 2 strings input and str. Print YES if the given str is a substring for the
        string. Otherwise, print NO

    ● Input ⇒ Outputs
        ○ ABCDEFG ABCD ⇒ YES
        ○ ABCDEFG ABCDEF ⇒ YES
        ○ ABCDEFG EFG ⇒ YES
        ○ ABCDEFG DEFG ⇒ YES
        ○ ABCDEFG BCD ⇒ YES
        ○ ABCDEFG DEF ⇒ YES
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

    int i = 0;
    while (input[i] != str[0]) {
        i++;
        if ((int)input.size() <= i) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int j = 1; j < (int)str.size(); ++j) {
        if (input[++i] != str[j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
