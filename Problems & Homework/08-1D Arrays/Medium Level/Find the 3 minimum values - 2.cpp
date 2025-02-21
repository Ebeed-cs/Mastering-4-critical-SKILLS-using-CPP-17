#include<iostream>
using namespace std;

/*			

				Find the 3 minimum values

		● Read integer N (>= 3), then read N integers. Find the 3 lowest numbers.
			○ Don’t change the array content
			○ Don’t iterate on the array more than once
	
		● Input ⇒ Output
			○ 5		4 1 3 10 8  ⇒  1 3 4     
			○ 3     7 9 -2  ⇒ -2 7 9 


*/

int main() {
    int N, input;
    cin >> N;

    int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX;

    for (int i = 0; i < N; i++) {
        cin >> input;

        if (input < min1) {
            min3 = min2;
            min2 = min1;
            min1 = input;
        }
        else if (input < min2) {
            min3 = min2;
            min2 = input;
        }
        else if (input < min3) {
            min3 = input;
        }
    }

    cout << min1 << " " << min2 << " " << min3;
    return 0;
}
