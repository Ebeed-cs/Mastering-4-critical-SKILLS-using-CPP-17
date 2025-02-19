#include<iostream>
#include <cmath>
using namespace std;

/*			[Explanation video]

				Smallest pair

		● Given a number N (<= 200) and an array A of N numbers.
		● Print the smallest possible result of A[i] + A[j] + j - i , where 1  ≤  i < j  ≤  N.

		● Input ⇒ Output
			○ 4   20 1 9 4    ⇒     7

*/

int main() {
    
    int n;
    cin >> n;
    int a[n];

    for (int i = 0; i < n; i++) cin >> a[i];

    int min_value = INT_MAX;
    int min_ai_minus_i = a[0] - 0; // A[i] - i for the first element

    for (int j = 1; j < n; j++) {
        min_value = min(min_value, min_ai_minus_i + a[j] + j);
        min_ai_minus_i = min(min_ai_minus_i, a[j] - j);
    }

    cout << min_value << endl;
    return 0;
}
