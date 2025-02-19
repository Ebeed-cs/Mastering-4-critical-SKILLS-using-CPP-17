#include<iostream>
using namespace std;

/*
				Replace MinMax

	● Read an integer N (< 200), then read N integers.
		○ Assume all values [0, 2000]
	● Print the array after doing the following operations:
		○ Find minimum number in these numbers.
		○ Find maximum number in these numbers.
		○ Replace each minimum number with maximum number and Vise Versa.

	● Input ⇒ Output
		○ 7      4 1 3 10 8 10 10 ⇒  4 10 3 1 8 1 1

*/

int main() {
	int N;
	cin >> N;
	int number[N];

	int min_num = 2000;
	int max_num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		if (number[i] > max_num)
			max_num = number[i];
		if (number[i] < min_num)
			min_num = number[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (number[i] == min_num)
			number[i] = max_num;

		else if (number[i] == max_num)
			number[i] = min_num;
	}

	for (int i = 0; i < N; ++i)
	{
		if(i)
			cout <<" ";
		
		cout << number[i];
	}
	return 0;
}
