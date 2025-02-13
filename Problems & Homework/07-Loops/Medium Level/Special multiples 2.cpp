#include<iostream>
using namespace std;

/*

		Special multiples 2

	● Read an integer N : Print the first N numbers that are
		○ multiple of 3 but not multiple of 4

	● Input: 11
	● Output: 3 6 9 15 18 21 27 30 33 39 42

	● Notice
		 ○ 12 is divisible by both 3 and 4 ⇒ so excluded

*/

int main() {
	int N, count = 0;
	int i = 0;
	cin >> N;
	while (N)
	{
		count += 3;
		if (!(count % 4 == 0))
			N--, cout << count << " ";
	}
	return 0;
}
