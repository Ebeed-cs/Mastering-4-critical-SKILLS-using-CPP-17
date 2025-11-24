#include<iostream>
using namespace std;


int main() {
	int a = 0, b = 1;

	cout << a++ << "\n";  // 0 [output]
	cout << ++a << "\n";  // 2 [output]
	a += 2 * b + 1;		 // 5
	b = ++a * 2;	// 12
	cout << a << " " << b << "\n";	// 6 12  [output]

	b = a;		// 6
	a = 12 + a / 3 / 2 - 2 * 2; // 9
	cout << a << "\n";	// 9  [output]

	a = b;	// 6
	a = ((12 + a) / 3 / 2 - 2) * 2;  // 2
	cout << a << "\n";	// 2  [output]

	return 0;
}

