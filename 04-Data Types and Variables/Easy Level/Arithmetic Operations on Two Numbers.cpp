#include <iostream>
using namespace std;

int main() {
    double num1, num2;
    cin >> num1 >> num2;
    cout << num1 << " + " << num2 << " = " << num1 + num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1 - num2 << endl;
    if (num2 != 0)
        cout << num1 << " / " << num2 << " = " << num1 / num2 << endl;
    else
        cout << "the second number must be non-zero value to can make divistion operation on it" << endl;
    cout << num1 << " * " << num2 << " = " << num1 * num2 << endl;
    return 0;
}
