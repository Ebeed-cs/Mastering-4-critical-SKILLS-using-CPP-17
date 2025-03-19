#include <iostream>
using namespace std;

/*
            Special print

        ● Read 2 integers for the rows and columns of a matrix ( <= 100). Then read rows x cols integer value.
        ● Print the following 4 values
            ○ The sum of the left diagonal & The sum of the right diagonal
            ○ The sum of the last row & The sum of the last column

        ● Input: 3 4
            ○ 8 16 9 52
            ○ 3 15 27 6
            ○ 14 25 2 10
        ● Output
            ○ 25 104
            ○ 51 68
*/

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
