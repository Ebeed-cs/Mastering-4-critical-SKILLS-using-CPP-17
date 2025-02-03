#include <iostream>
using namespace std;
/*
Write a program that reads 2 numbers and print their +, -, *, / as following

Input 
12 3

Output
12 + 3 = 15
12 - 3 = 9
12 / 3 = 4
12 * 3 = 36 

Do good testing for your code

E.g. consider zero as first or 2nd number
E.g. consider negative values
E.g. even and odd values
E.g. try the MAX of int: 2147483647

 */
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

