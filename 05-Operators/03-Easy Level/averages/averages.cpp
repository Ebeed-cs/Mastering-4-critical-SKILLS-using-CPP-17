#include<iostream>
using namespace std;


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

