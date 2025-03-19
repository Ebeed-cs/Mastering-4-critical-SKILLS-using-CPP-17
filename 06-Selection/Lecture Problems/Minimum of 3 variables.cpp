#include<iostream>
using namespace std;
/*
	Minimum of three variables
*/

int main() {

	int num1, num2, num3;
	cout << "Enter the three numbers :";
	cin >> num1 >> num2 >> num3;
	// Approach 1
	cout << "the Minimum number is ";
	if (num1 < num2)
		if (num1 < num3)
			cout << num1 << endl;
		else
			cout << num3 << endl;
	else
		if (num2 < num3)
			cout << num2 << endl;
		else
			cout << num3 << endl;

	// Approac 2	'good for scalability'
	int temp = num3;
	if (temp > num1)
		temp = num1;
	if (temp > num2)
		temp = num2;
	cout << "the Minimum number is ";
	cout << temp << endl;
	return 0;
}
