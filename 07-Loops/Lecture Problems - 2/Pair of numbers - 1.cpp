#include<iostream>
using namespace std;
					// Approach 1
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
	int N, M, sum , count = 0;
	cin >> N >> M >> sum;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (i + j == sum)
				count ++;
	
	cout << count << endl;
	return 0;
}
