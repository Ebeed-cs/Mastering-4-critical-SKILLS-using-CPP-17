#include<iostream>
using namespace std;
/*									Approach 2
									[Explanation video]

				Triples of numbers

	● Read N, M, W. Find all triples that has A + B <= C where
		○ 1 <= A <= N
		○ A <= B <= M
		○ 1 <= C <= W


*/

int main() {
	int N, M, W, count = 0;
	cin >> N >> M >> W;
	for (int i = 1; i <= N; i++)
		for (int k = 1; k <= W; ++k)
		{
			int j = k - i; // i + j = k 
			if ( j <= M && j >= i)
				count += W - k + 1;
		}

	cout << count << endl;
	return 0;
}
