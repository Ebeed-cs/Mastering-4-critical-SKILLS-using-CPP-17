#include<iostream>
using namespace std;

/*

				Is Palindrome?

	● Read integer N (< 1000), then read N integers of an array.
	● Determine if the array is palindrome or not.
	● An array is called palindrome if it reads the same backward and forward
		○ for example, arrays { 1 } and { 1,2,3,2,1 } are palindrome
		○ while arrays { 1,12 } and { 4,7,5,4 } are not.

	● Inputs ⇒ Outputs
		○ 5   1 3 2 3 1  ⇒ YES
		○ 4   1 2 3 4  ⇒ NO





*/

int main() {
	int N;
	cin >> N;
	int number[N / 2];
	for (int i = 0; i < N / 2; ++i)
		cin >> number[i];

	int input;

	if (N % 2 != 0)
		cin >> input;

	for (int j = N / 2 - 1; j >= 0; --j)
	{
		cin >> input;
		if (number[j] != input)
		{
			cout << "No" << endl;
			return 0;
		}
	}

	cout << "Yes" << endl;
	return 0;
}



