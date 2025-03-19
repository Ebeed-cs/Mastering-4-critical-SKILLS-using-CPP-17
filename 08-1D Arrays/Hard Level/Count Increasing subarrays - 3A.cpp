#include<iostream>
using namespace std;

/*						Approach 3 - A
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
    
    int count = 0;
    int streak = 0;
    int prev;
    
    // Read first element outside the loop
    if (N > 0) {
        cin >> prev;
        streak = 1; // Start with streak of 1 for the first element
    }
    
    // Single loop to read remaining elements and process them
    for (int i = 1; i < N; i++) {
        int current;
        cin >> current;
        
        if (current >= prev) {
            streak++;
        } else {
            // End of a streak, add all subarrays from this streak
            count += (streak * (streak + 1)) / 2;
            streak = 1; // Reset streak for the current element
        }
        
        prev = current;
    }
    
    // Don't forget to add the last streak
    count += (streak * (streak + 1)) / 2;
    
    cout << count << endl;
    return 0;
}
