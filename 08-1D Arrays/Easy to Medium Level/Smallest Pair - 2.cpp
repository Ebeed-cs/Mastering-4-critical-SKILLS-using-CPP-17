#include<iostream>
#include <cmath>
using namespace std;


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

