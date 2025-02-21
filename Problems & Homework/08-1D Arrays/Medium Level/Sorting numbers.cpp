#include<iostream>
using namespace std;

/*
			Sorting numbers

	● Read integer N ( <= 900), followed by reading N integers (0 <= value <= 500)
	● Print the sorted list of the numbers

	● Input:    13      1 5 5 2 5 7 2 3 3 3 5 2 7
	● Output: 1 2 2 2 3 3 3 5 5 5 5 7 7
	● Give your most efficient trial
		○ You don’t need to google how to sort numbers
		○ Hint: max value in the array is 500

*/

int main() {
	int N;
	cin >> N;
	const int SIZE = 500 + 1;
	int freq[SIZE] = { 0 };
	int input;

	for (int i = 0; i < N; ++i) cin >> input, freq[input]++;

	for (int i = 0; i < SIZE; ++i)
		while (freq[i]--)
			cout << i << " ";

	return 0;
}

// This is called count sort algorithm. The most efficient if values are small :)
