#include<iostream>
using namespace std;

int main() {
	int x, count = 0;
	cin >> x;

	if (x == 0)  // fix the first bug 
		count = 1;
	else
	{
		while (x != 0)	// fix the second bug : (x > 0) -> ( x != 0)
		{
			x /= 10;
			count++;
		}
	}

	cout << count << endl;
	return 0;
}

/*

	the first bug is:
		0 -> 0
		Mathematical Definition:
	The number 0 is a single-digit number.
	So, if a user enters 0, your program should return 1, not 0

	the second bug is:
		negative numbers -> 0

*/

/*
	C++   : -1/10 => 0
 	Python: -1/10 => -1
 
    Be careful from -ve values with division and modulus
*/
