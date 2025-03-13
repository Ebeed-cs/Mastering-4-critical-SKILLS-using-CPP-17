#include<iostream>
using namespace std;
								// [Explanation video]
/*						Approach 3 - B
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

    int count = 0, prev, len;
    if (N > 0) {
        cin >> prev;
        len = 1;
    }

    int current;
    for (int i = 1; i < N; ++i) {
        cin >> current;
        if (current >= prev) {
            count += len;  // Add the number of new increasing subarrays
            ++len;         // Increase the length of current streak
        } else {
            len = 1;       // Reset streak length to 1
        }
        prev = current;
    }

    cout << count + N << endl;  // Add N for all single-element subarrays
    return 0;
}
 
