#include<iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	num /= 1000;
	cout << num % 10 << endl;
	return 0;
}

	// 1000 => removes last 3 digits
	// %10 get next digit = 4th
