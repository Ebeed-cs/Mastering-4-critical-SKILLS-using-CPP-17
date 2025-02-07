#include<iostream>
using namespace std;

/*

	 Last 3 digits sum
 ● Write a program that reads an integer and prints the sum of its last 3 digits.
 ● Inputs ⇒ Outputs examples
	○ 15    ⇒ 6
	○ 125   ⇒ 8
	○ 1000  ⇒ 0
	○ 1001  ⇒ 1
	○ 1234  ⇒ 9
	○ 99999 ⇒ 27

*/

int main() {
	int num, sum = 0;
	cin >> num;
	sum += num % 10;
	num /= 10;

	sum += num % 10;
	num /= 10;

	sum += num % 10;
	
	cout << sum << endl;
	return 0;
}
