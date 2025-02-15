#include<iostream>
using namespace std;
								// Approach 2
/*

				Pair of numbers

	● Read N, M, SUM. Find all pairs that has A + B == SUM where
		○ 1 <= A <= N
		○ 1 <= B <= M

	● Try input
		○ 1000000 1000000 1000000
		○ How many steps the code do?

*/

int main() {
	int N, M, sum, count = 0;
	cin >> N >> M >> sum;
	for (int i = 1; i <= N; i++)
	{
		int j = sum - i;
		if (j >= 1 && j <= M)
			count++;
	}
	cout << count << endl;
	return 0;
}

/*
		note that we have two conditions on on j: 
			first one -> must be in the range from 1 to m 'inclusive'
			second one -> must satisfy that formula ' j + i = sum'
		
		and like that we have condition on i: 
			first -> in the range from 1 to n 'inclusive'
			second -> satisfy the formula ' i + j = sum'
*/
