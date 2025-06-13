#include<iostream>
using namespace std;

/*
					Reverse in place

		● Read an Integer N, then read N <= 200 integers.
			○ In-place: Change the current array, don’t use 2 arrays
		● Simple idea: Iterate from the begin and end in same time
			○ Swap the 2 positions
			○ Do this tell the middle only
		● Let say array is 1 2 3 4 5 6 7 8
			○ Step 1: swap (1, 8) ⇒ 8 2 3 4 5 6 7 1
			○ Step 2: swap (2, 7) ⇒ 8 7 3 4 5 6 2 1
			○ Step 3: swap (3, 6) ⇒ 8 7 6 4 5 3 2 1
			○ Step 4: swap (4, 6) ⇒ 8 7 6 5 4 3 2 1
				■ Stop after n/2 steps



*/

int main() {
	int N;
	cin >> N;
	int number[N];
	for (int i = 0; i < N; ++i)
		cin >> number[i];

	for (int i = 0; i < N / 2; ++i)
	{
		number[i] = number[i] + number[N - i - 1];
		number[N - i - 1] = number[i] - number[N - i - 1];
		number[i] = number[i] - number[N - i - 1];
	}

	for (int i = 0; i < N; ++i)
		cout << number[i] << " ";
	return 0;
}
