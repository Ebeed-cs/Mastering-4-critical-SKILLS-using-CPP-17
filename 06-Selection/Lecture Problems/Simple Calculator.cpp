#include<iostream>
using namespace std;


int main() {
	int num1, num2;
	cout << "Enter the two numbers :";
	cin >> num1 >> num2;
	cout << num1 << " + " << num2 << " = " <<  num1 + num2 << endl;
	cout << num1 << " - " << num2 << " = " <<  num1 - num2 << endl;
	if(num2 == 0)
		cout << "can't divide it" << endl;
	else
		cout << num1 << " / " << num2 << " = " <<  num1 / num2 << endl;
	cout << num1 << " * " << num2 << " = " <<  num1 * num2 << endl;
	return 0;
}
