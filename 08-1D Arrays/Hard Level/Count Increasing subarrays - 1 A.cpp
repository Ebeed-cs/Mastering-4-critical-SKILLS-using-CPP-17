#include<iostream>
using namespace std;

/*					Approach 1 - A
					Count increasing subarrays

		● Read an Integer N, then read N (< 200) integers.
		● Output: Count how many subarrays are increasing in the array.
		● E.g. If input  is 1 2 3 4
			○ We can find all sublists of length 1 ⇒ [1], [2], [3], [4]
			○ All sublists of length 2 ⇒ [1, 2], [2, 3], [3, 4]
			○ All sublists of length 3 ⇒ [1, 2, 3], [2, 3, 4]
			○ All sublists of length 4 ⇒ [1, 2, 3, 4]

		● Inputs ⇒ Outputs
			○ 4 1 2 3 4  ⇒ 10    [10 sub-arrays from previous example, all are increasing]
			○ 4 4 3 2 1 ⇒ 4       [only sub-arrays of length 1 can be considered]
			○ 4 10 20 1 5 ⇒ 6
		● Easy using 3 nested loops. Medium using 2 loops. Hard with 1 loop


*/

int main() {
	int N;
	cin >> N;
	int number[N];

	for(int i = 0; i < N; ++i) cin >> number[i];

	int count = 0, num = INT_MIN;
	bool increasing = true;
	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
		{
			for (int k = i; k < j + 1; ++k)
			{
				if (num > number[k])
				{
					increasing = false;
					break;
				}
				num = number[k];
			}
			if (increasing)
				count++;
			increasing = true;
			num = INT_MIN;
		}

	cout << count << endl;
	return 0;
}
