#include <iostream>
using namespace std;

/*
                       Compressing

    ● Read a string of letters and then compress each group of same letter
        ○ E.g. if the sub-string is cccc ⇒ c4
        ○ Use _ between each group

    ● Input ⇒ Outputs
        ○ ccccDDDxxxxxxxxe ⇒ c4_D3_x8_e1
        ○ xxxxxxxx ⇒ x8

*/

int main() {
    string input;
    cin >> input;

    int num, count;
    count = num = 0;

    while (num < (int)input.size()) {
        if (num && input[num] != input[num - 1]) {
            cout << input[num - 1] << count << "_";
            count = 0;
        }
        count++;
        num++;
    }
    cout << input[num - 1] << count;
    return 0;
}
