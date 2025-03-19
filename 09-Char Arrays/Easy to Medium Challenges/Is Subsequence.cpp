#include <iostream>
using namespace std;

/*
                        Is Subsequence?

    ● Read 2 strings input and str. Print YES if the given str is a subsequence for
        the string. Otherwise, print NO

    ● Input ⇒ Outputs
        ○ ABCDEFG ABCD ⇒ YES
        ○ ABCDEFG ABCDEF ⇒ YES
        ○ ABCDEFG EFG ⇒ YES
        ○ ABCDEFG DEFG ⇒ YES
        ○ ABCDEFG BCD ⇒ YES
        ○ ABCDEFG DEF ⇒ YES
        ○ ABCDEFG ACEG ⇒ YES
        ○ ABCDEFG DG ⇒ YES
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

    int count , str_size;
    str_size = count = 0;

    while(count < input.size())
        if(input[count ++] == str[str_size]) str_size++;
    
    if(str_size != str.size() - 1)
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
