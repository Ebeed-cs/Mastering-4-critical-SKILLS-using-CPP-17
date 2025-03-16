#include <iostream>
using namespace std;

/*
                Smaller row?

    ● Read integers N, M, then Read matrix NxM. Then read Q for Q queries.
    ● Each query is 2 integers: first and 2nd row indices (1-based)
    ● Compare the 2 rows and print YES if first row < 2nd for all the row values

    ● Input ⇒ Output
        ○ 3 4
        ○ 8 16 9 52
        ○ 3 15 27 6
        ○ 14 25 29 10
        ○ 3
        ○ 1 2 ⇒ NO
        ○ 2 3 ⇒ YES
        ○ 1 3 ⇒ NO

*/

int main() {
    int row, col;
    cin >> row >> col;
    int arr[row][col];

    for (int i = 0; i < row; ++i)
        for (int j = 0; j < col; ++j)
            cin >> arr[i][j];

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i) {
        int first, second;
        cin >> first >> second;

        first--, second--;
        bool smaller = true;
        for (int j = 0; j < col; ++j) {
            if (arr[first][j] >= arr[second][j]) {
                smaller = false;
                break;
            }
        }

        if (smaller)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
