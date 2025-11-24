#include <iostream>
using namespace std;


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
