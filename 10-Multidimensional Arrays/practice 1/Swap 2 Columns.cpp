#include <iostream>
using namespace std;

/*
                                    Swap 2 columns

        ● Read integers N, M, then Read matrix NxM. Then read 2 indices of columns. Swap the 2 columns together. Print the new matrix.

        ● Input: 3 4
            ○ 8 16 9 52
            ○ 3 15 27 6
            ○ 14 25 2 10
            ○ 0 3
        ● Output
            ○ 52 16 9 8
            ○ 6 15 27 3
            ○ 10 25 2 14
*/

int main() {
    int row, col;
    cin >> row >> col;
    int max_index = row * col;
    int matrix[row][col];

    for (int k = 0; k < max_index; ++k)
    {
        int i = k / col;
        int j = k % col;
        cin >> matrix[i][j];
    }

    int index1, index2;
    cin >> index1 >> index2;

    int i = row - 1;
    while (i >= 0)
    {
        matrix[i][index1] = matrix[i][index1] + matrix[i][index2];
        matrix[i][index2] = matrix[i][index1] - matrix[i][index2];
        matrix[i][index1] = matrix[i][index1] - matrix[i][index2];
        --i;
    }

    for (int k = 0; k < max_index; ++k)
    {
        int i = k / col;
        int j = k % col;
        cout << matrix[i][j] << " ";

        if (j == col - 1)
            cout << endl;
    }
    return 0;
}
