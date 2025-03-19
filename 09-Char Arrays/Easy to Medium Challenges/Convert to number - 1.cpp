#include <iostream>
using namespace std;

/*
                        Convert to number - 1

    ● Read a string of 6 letters maximum, convert it to int then print
        ○ the number, the number multiplied by 3

    ● Input ⇒ output
        ○ “100” ⇒ 100 300
        ○ “0200” ⇒ 200 600

*/

int main() {
    string input;
    cin >> input;

    int num = 0;

    int mul = 1;
    for (int i = input.size() - 1; i >= 0 ; --i) {
        num += (input[i] - '0') * mul;
        mul *= 10;
    }

    cout << num << " " << num * 3 << endl;
    return 0;
}
