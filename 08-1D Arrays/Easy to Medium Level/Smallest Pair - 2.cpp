#include<iostream>
#include <cmath>
using namespace std;

/*			[Explanation video]

				Smallest pair

		● Given a number N (<= 200) and an array A of N numbers.
		● Print the smallest possible result of A[i] + A[j] + j - i , where 1  ≤  i < j  ≤  N.

		● Input ⇒ Output
			○ 4   20 1 9 4    ⇒     7

*/

int main() {
	int N;
	cin >> N;
	int A[N];
	for (int i = 0; i < N; ++i) cin >> A[i];

	int min_num = INT_MAX;
	int min_aj_plus_j = A[N - 1] + N - 1;

	for (int j = N - 2; j >= 0; --j)
	{
		min_num = min(min_num, min_aj_plus_j + A[j] - j);
		min_aj_plus_j = min(min_aj_plus_j, A[j] + j);
	}

	cout << min_num << endl;

	return 0;
}

