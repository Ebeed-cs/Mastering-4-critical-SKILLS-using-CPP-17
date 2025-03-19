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
	const int N = 199;
	int n, arr[N], k, min_index, max_sum = -10000000;

	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

    // Try every window
	for (int i = 0; i < n - k + 1; i++) {
		int sum = 0;
		for (int j = 0; j < k; ++j)
			sum += arr[i + j];

		if (sum > max_sum) {
			max_sum = sum;
			min_index = i;

		}
	}
	cout << min_index << " " << min_index + k - 1 << " " << max_sum << "\n";

}
