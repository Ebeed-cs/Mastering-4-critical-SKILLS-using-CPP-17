#include <iostream>
using namespace std;


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
