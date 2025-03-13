#include <iostream>
using namespace std;

/*                                              // approach 2 'using two loops'
                    longest subarray

        Read integer N (< 1000) then N read numbers each is either 0 or 1.
        ● Find the longest subarray with number of zeros = numbers of ones
            ○ You can easily implement it using 3 loops
            ○ Or with little thinking using 2 loops (even with no extra arrays)
            ○ Hard: You can implement it without any nested loops
        ● Inputs ⇒ outputs
            ○ 7 1 0 0 0 1 1 1 ⇒ 6 (e.g. 100011 or 000111)
            ○ 19 1 0 0 0 0 0 1 0 1 1 0 1 0 0 0 0 0 0 1 ⇒ 8 (e.g. 00101101)

*/

int main() {
    int N;
    cin >> N;
    int arr[1000];
    int max = 0;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    for (int start = 0;start < N - 1; ++start) {
        int one_count = 0;
        int zero_count = 0;
        for (int end = start; end < N; ++end) {
            if (arr[end]) one_count++;
            else zero_count++;
            if ((one_count == zero_count) && (max < one_count)) max = one_count;
        }
    }
    cout << max * 2 << endl;
    return 0;
}
