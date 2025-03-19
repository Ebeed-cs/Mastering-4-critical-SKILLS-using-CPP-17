#include<iostream>
using namespace std;

/*

		Special Multiples

	Write a program that reads an integer 𝑁 and prints all numbers from
	0 to 𝑁 that satisfy at least one of the following conditions:

		The number is divisible by 8.
		The number is divisible by both 4 and 3 (simultaneously).

	● Input: 100
	● Output: 0 8 12 16 24 32 36 40 48 56 60 64 72 80 84 88 96

*/

int main() {
	int N, count = 0;
	cin >> N;
	while (count < N)
	{
		if ((count % 8 == 0) || ((count % 4 == 0) && (count % 3 == 0)))
			cout << count << " ";
		count++;
	}
	return 0;
}
