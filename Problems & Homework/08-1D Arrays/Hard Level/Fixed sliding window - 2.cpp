#include<iostream>
using namespace std;

/*
			 Fixed sliding window

			 https://www.researchgate.net/profile/Ali_Raza98/publication/325158306/figure/fig5/AS:681968115134465@1539605277480/Sliding-window-technique.ppm

	● Read Integers K and N, (where K <= N). then read N < 200 integers.
	● Find sub-array (consecutive numbers) of K elements that has maximum sum

	● Input   3  7        1 0 3 -4 2  -6 9
		○ Let’s list all sub-arrays of length 3
		○ 1 0 3    ⇒ sum = 4
		○ 0 3 -4   ⇒ sum = -1
		○ 3 -4 2   ⇒ sum = 1
		○-4 2 -6   ⇒ sum = -8
		○ 2 -6 9   ⇒ sum = 5

	● Output: 4 6  5          (Sub-array from indices 4 to 6 has maximum sum of 5)
	● Can you do it without nested loops? There are 2 ways.

*/

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
