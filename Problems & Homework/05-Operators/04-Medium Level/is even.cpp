#include<iostream>
using namespace std;

/*

	The following code reads an integer and computes a boolean if the number is even in 3 different ways.
● Fill in the is_even to solve the problem in 3 ways as following
	● Using only %2
	● Using only /2
	● Using only %10

*/
int main() {
	int num;
	cin >> num;

	// Is even using %2
	bool is_even1 = !(num % 2 == 0);
	cout << is_even1 << endl;

	/*
		note here (num % 2) only is a fault beacouse (-2 % 2) -> !true -> false
		while it actually an even number 
	*/
	// Is even using /2
	bool is_even2 = !(((double)num / 2.0 - num / 2) > 0);
	cout << is_even2 << endl;
	/*
		if found remainder then the number is odd
		5 / 2 = 2.5 (odd), 4 / 2 = 2.0 (even)
	*/

	// Is even using %10
	int L_digit = num % 10;
	bool is_even3 = !(L_digit % 2);
	cout << is_even3 << endl;

	// another solution 
	int last_digit = num % 10;	
	
	// even last digit is 0, 2, 4, 6, 8
	bool is_even3_2 = last_digit == 0 || last_digit == 2 || last_digit == 4 || last_digit == 6 || last_digit == 8;
	cout << is_even3 << endl;

	return 0;
}
