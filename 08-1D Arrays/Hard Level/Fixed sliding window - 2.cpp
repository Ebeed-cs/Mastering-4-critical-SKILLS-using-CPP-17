#include<iostream>
using namespace std;


int main() {
	int K, N;
	cin >> K >> N;
	int k_arr[K];

	int input, last_index, sum = 0, max_sum = INT_MIN;
	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		if (i >= K)
			sum -= k_arr[i % K];

		k_arr[i % K] = input;
		sum += input;

		if (i >= K - 1)
			if (sum > max_sum)
				max_sum = sum, last_index = i;
	}

	cout << last_index - K + 1 << " " << last_index << " " << max_sum << endl;
	return 0;
}
