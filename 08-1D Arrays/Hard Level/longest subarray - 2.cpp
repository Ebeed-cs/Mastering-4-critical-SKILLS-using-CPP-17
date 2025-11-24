#include <iostream>
using namespace std;

/*                                              // approach 2 'using two loops'
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
