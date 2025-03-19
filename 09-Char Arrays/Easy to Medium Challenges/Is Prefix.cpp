#include <iostream>
using namespace std;

/*
                        Is Prefix?

        ● Read 2 strings input and str. Print YES if the given str is a prefix for the string.Otherwise, print NO

        ● Input ⇒ Outputs
            ○ ABCDEFG ABCD ⇒ YES
            ○ ABCDEFG ABCDEF ⇒ YES
            ○ ABCDEFG EFG ⇒ NO
            ○ ABCDEFG DEFG ⇒ NO
            ○ ABCDEFG BCD ⇒ NO
            ○ ABCDEFG DEF ⇒ NO
            ○ ABCDEFG ACEG ⇒ NO
            ○ ABCDEFG DG ⇒ NO
            ○ ABCDEFG GD ⇒ NO
            ○ ABCDEFG ABCDEFG ⇒ YES

*/

int main() {
    string input , str;
    cin >> input >> str;

    if(str.size() > input.size()){
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < (int) str.size(); ++i){
        if(input[i] != str[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
