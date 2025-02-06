#include<iostream>
using namespace std;

/*
	 Averages
 ● Write a program that reads 5 numbers and print the following:
	○ A) Their average
	○ B) The sum of the first 3 numbers divided by the sum of the last 2 numbers
	○ C) The average of the first 3 numbers divided by the average of the last 2 numbers.
 ○ What is the math relation between B and C?

EX:
 ● Input 1 2 3 4  5
 ○ 3
 ○ 0.666666667
 ○ 0.444444444

*/
int main() {
	double num1, num2, num3, num4, num5;
	cin >> num1 >> num2 >> num3 >> num4 >> num5;
	double A = (num1 + num2 + num3 + num4 + num5) / 5;
	cout << A << endl;

	double B = (num1 + num2 + num3) / (num4 + num5);
	cout << B << endl;

	double c1 = (num1 + num2 + num3) / 3;
	double c2 = (num4 + num5) / 2;
	double C = c1 / c2;
	cout << C << endl;

	return 0;
}

/*
	the relation between B and C : 
	C = B * 2/3
*/

