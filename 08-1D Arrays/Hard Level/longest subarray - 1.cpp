#include <iostream>
using namespace std;

/*                                              // approach 1 'with three loops'
*/

int main() {
    int N;
    cin >> N;
    int arr[N];
    int max = 0;
    for (int i = 0; i < N; ++i) cin >> arr[i];

    for (int start = 0; start < N; ++start) {
        for (int end = start + 1; end < N; ++end) {
            int one_count = 0;
            int zero_count = 0;
            for (int k = start; k <= end; ++k) {
                if (arr[k])
                    one_count++;
                else
                    zero_count++;
            }
            if ((one_count == zero_count) && (one_count > max) ) max = one_count;
        }
    }

    cout << max * 2 << endl;
    return 0;
}
