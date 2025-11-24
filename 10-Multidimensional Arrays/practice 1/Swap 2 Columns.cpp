#include <iostream>
using namespace std;

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
