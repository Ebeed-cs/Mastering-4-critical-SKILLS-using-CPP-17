#include <iostream>
using namespace std;

/*
                Triangular matrix - 1

    ● Read integer N, then Read Square matrix NxN. Then, print 2 values. The sum of the lower triangle matrix and the upper triangle.

    ● Input
        ○ 3
        ○ 8 16 9
        ○ 3 15 27
        ○ 14 25 29
    ● Output
        ○ 94 (8+15+29+3+25+14)
        ○ 104 (8+15+29+16+27+9)

*/

int main() {
    int N;
    cin >> N;
    int arr[N][N];

    int lower_sum, upper_sum;
    lower_sum = upper_sum = 0;

    for (int i = 0; i < N; ++i) {
        bool upper = false;
        for (int j = 0; j < N; ++j) {
            cin >> arr[i][j];
            if (i != j) {  
                if (!upper)
                    lower_sum += arr[i][j];
                else
                    upper_sum += arr[i][j];
            }
            else {
                lower_sum += arr[i][j];
                upper_sum += arr[i][j];
                upper = true;
            }
        }
    }

    cout << lower_sum << " " << upper_sum;
    return 0;
}

/*
    when appear the diagonal it turn from upper to lower or reverse
*/
