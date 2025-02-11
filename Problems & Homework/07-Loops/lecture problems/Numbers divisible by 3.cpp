#include<iostream>
using namespace std;

/*
	Read an integer X, find all numbers divisible by 3 from 1 to X.
		○ These are 3, 6, 9, 12, 15, 18, ….. (multiple of 3)

*/

int main() {
	int x, result = 1;
	cin >> x;
	while (--x)
	{
		if (++result % 3 == 0)
			cout << result << " ";
	}
	return 0;
}
