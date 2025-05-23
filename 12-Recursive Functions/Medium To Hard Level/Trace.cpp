#include <iostream>
using namespace std;
/*
	   Trace

	● Without running code
		○ Trace by hand: What does this method do?
		○ What happens if we swapped lines 6 & 7?

		void do_something(int n) {
			if (n) {
			cout << n % 10;
			do_something(n /10);
}}

			int main() {
			do_something(123456);
			return 0;

		}

*/

void do_something1(int n) {	// print number digit by digit reversed -> // 654321
	if (n) {
		cout << n % 10;
		do_something1(n / 10);
	}
}

void do_something2(int n) { // 123456
	if (n) {
		do_something2(n / 10);
		cout << n % 10;
	}
}

int main() {
	do_something1(123456);
	cout << "\n";
	do_something2(123456);

	return 0;
}
