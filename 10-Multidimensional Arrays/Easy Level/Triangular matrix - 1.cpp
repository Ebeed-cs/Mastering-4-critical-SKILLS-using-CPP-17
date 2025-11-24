#include <iostream>
using namespace std;


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
