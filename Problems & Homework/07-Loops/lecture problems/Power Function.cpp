#include<iostream>
using namespace std;

/*
	 Read 2 integers x and Y and compute XY.
		○ This means X * X * X ….. Y times
		○ E.g = 2 5 = 2 * 2 * 2 * 2 * 2


*/

int main() {
	int num, pow, result = 1;
	cin >> num >> pow;
	while (pow >= 1)
	{
		result *= num;
		--pow;
	}
		cout << result << endl;
	return 0;
}
