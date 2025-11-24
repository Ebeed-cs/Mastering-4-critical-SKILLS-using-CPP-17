#include<iostream>
using namespace std;


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
