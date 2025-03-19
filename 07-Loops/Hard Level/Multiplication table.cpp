#include<iostream>
using namespace std;

/*
			Multiplication table
	● Given two integers N and M:
      - Print the multiplication table for all numbers.
      - Each number (from 1 to N) should be multiplied by all numbers from 1 to M.

	● Input 3 4
	● Output           
		○ 1 x 1 = 1
		○ 1 x 2 = 2
		○ 1 x 3 = 3
		○ 1 x 4 = 4

		○ 2 x 1 = 2
		○ 2 x 2 = 4
		○ 2 x 3 = 6
		○ 2 x 4 = 8

		○ 3 x 1 = 3
		○ 3 x 2 = 6
		○ 3 x 3 = 9
		○ 3 x 4 = 12


*/

int main() {
	int N, M, count;
	cin >> N >> M;
	int left = 0;
	while (N > 0)
	{
		count = 1;
		left++;
		while (count <= M)
		{
			cout << left << " x " << count << " = " << left * count << endl;
			count++;
		}
		N--;
	}
	return 0;
}
