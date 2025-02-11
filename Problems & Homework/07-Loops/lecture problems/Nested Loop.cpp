#include<iostream>
using namespace std;

/*

				Nested Loop

	Write a program that reads integer T for T test cases.
		● Then read T numbers:
			○ for each number N print sum of 1 to N
		● Remember, we can replace the sum with formula N * (N+1) / 2
			○ Which is more efficient?


*/

int main() {
	int T;
	cin >> T;

	while (T > 0) {
		int num;
		cin >> num;

		int sum = 0;
		int start = 1;

		while (start <= num) {
			sum += start;
			start++;
		}
		--T;
		cout << "Sum from 1 to " << num << " = " << sum << "\n";
	}

	return 0;
}
