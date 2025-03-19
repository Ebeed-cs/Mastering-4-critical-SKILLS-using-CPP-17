#include<iostream>
using namespace std;

/*
				Find most frequent number

	● Read an Integer N, then read N <= 200 integers. Find the value that repeated the most number of times.
			○ Each integer is 0 <= integer <= 150
	● Example for array: 1 2 1 3 1 5 5
			 1 repeated 3 times


*/

int main() {
	int N;
	cin >> N;
	int number[N];
	int reapeated_num[150] = {0};
	
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		reapeated_num[number[i] - 1]++;
	}

	int max_repeated_index = 0;

	for (int j = 0; j < 150; ++j)
		if (reapeated_num[max_repeated_index] < reapeated_num[j])
			max_repeated_index = j;
			
	cout << max_repeated_index + 1 << " repeated " << reapeated_num[max_repeated_index] << " times" << endl;
	return 0;
}

/*
We used a trick called frequency array
*/