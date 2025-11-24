#include <iostream>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;
    int max_index = row * col;

    int left_diagonal, right_diagonal, last_row, last_col;
    left_diagonal = right_diagonal = last_row = last_col = 0;

    int input;
    for (int k = 0; k < max_index; ++k)
    {
        int i = k / col;
        int j = k % col;

        cin >> input;

        if (i == j)
            left_diagonal += input;
        if (j == (col - i - 1))
            right_diagonal += input;
        if (i == (row - 1))
            last_row += input;
        if (j == (col - 1))
            last_col += input;
    }
    cout << endl;

    cout << left_diagonal << " " << right_diagonal << " " << last_row << " " << last_col;
    return 0;
}
