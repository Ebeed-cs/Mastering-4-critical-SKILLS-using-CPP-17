#include<iostream>
using namespace std;

/*
	Is even? Print digits
	Read an integer N, then do the following
		if the number is even: print last digit of it
		if the number is odd: do following:
			- if number < 1000, print last 2 digits
			- if number > 1000 and number < 1000000, print last 4 digits
			- otherwise, print its negative value
	testing examples of good coverage: 
		- 234 => even => 4
		- 157 => 57
		- 56169 => 6169
		- 1000001 => -1000001
*/

int main() {
	int num;
	cin >> num;
	if(num % 2 == 0)
		cout << num % 10 << endl;
	else	
		if(num <= 1000)	
			cout << num % 100 << endl;
		else if(num < 1000000)
			cout << num % 10000 << endl;
		else 
			cout << - num << endl;
	return 0;
}
