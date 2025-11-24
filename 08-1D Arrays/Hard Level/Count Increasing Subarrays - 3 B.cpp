#include<iostream>
using namespace std;
								// [Explanation video]
/*						Approach 3 - B

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
 
