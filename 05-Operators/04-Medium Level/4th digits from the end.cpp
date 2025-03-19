#include<iostream>
using namespace std;

/*

	 4th digits from the end
 ● Write a program that reads an integer and print the 4th from the right side. If
no such digit, print 0
 ● Inputs ⇒ Outputs examples
	○ 15     ⇒ 0
	○ 125    ⇒ 0
	○ 1000   ⇒ 1
	○ 5001   ⇒ 5
	○ 1234   ⇒ 1
	○ 654321 => 4
	○ 99999  ⇒ 9

*/

int main() {
	int num;
	cin >> num;
	num /= 1000;
	cout << num % 10 << endl;
	return 0;
}

	// 1000 => removes last 3 digits
	// %10 get next digit = 4th
