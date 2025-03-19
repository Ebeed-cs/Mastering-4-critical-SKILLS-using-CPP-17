#include<iostream>
using namespace std;

/*					
					Approach 2
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

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		count ++;    // single element is always valid
		for (int j = i + 1; j < N ; ++j)
		{
			if(number[j] <= number[j - 1])	
				break;
			count ++;
		}
	}

	cout << count << endl;
	return 0;
}

/*
i = 0:
  j = 0: [1] valid ✓
  j = 1: [1,2] check if 2>1 ✓
  j = 2: [1,2,3] check if 3>2 ✓
  j = 3: [1,2,3,4] check if 4>3 ✓

i = 1:
  j = 1: [2] valid ✓
  j = 2: [2,3] check if 3>2 ✓
  j = 3: [2,3,4] check if 4>3 ✓
...
*/
