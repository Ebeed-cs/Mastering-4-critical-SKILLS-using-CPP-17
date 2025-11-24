#include <iostream>
using namespace std;


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
