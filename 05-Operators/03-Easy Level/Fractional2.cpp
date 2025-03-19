#include<iostream>
using namespace std;


/*
By https://www.udemy.com/user/anishdalal4/
    Anish Dalal
Alternative Solution for Division and Modulus (only print fractional part)

* The fractional part is calculated by using the remainder. So for example 27/5 = (25 + 2) / 5 = 25/5 + 2/5. 
* We are only interested in the 2/5 part. So we can calculate the remainder using modulo and then divide it by the second number.
*/
int main() {

    int a, b; 
    cin >> a >> b; 
    double remainder = a % b; 
    double result = remainder / b; 
    cout << result << endl;

	return 0;
}

