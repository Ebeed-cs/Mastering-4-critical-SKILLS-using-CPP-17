#include <iostream>
using namespace std;


int main() {
    int row, col;
    cin >> row >> col;
    
    // Create the matrix and read input
    int matrix[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }
    
    int i = 0, j = 0; // Start at position (0,0)
    int sum = matrix[0][0]; // Include starting position value
    
    while (i < row-1 || j < col-1) { // Continue until we can't move anymore
        int right = -1, diagonal = -1, bottom = -1;
        
        // Check right move if valid
        if (j + 1 < col) {
            right = matrix[i][j + 1];
        }
        
        // Check bottom move if valid
        if (i + 1 < row) {
            bottom = matrix[i + 1][j];
        }
        
        // Check diagonal move if valid
        if (i + 1 < row && j + 1 < col) {
            diagonal = matrix[i + 1][j + 1];
        }
        
        // Find maximum among valid moves
        // If we can't move in a direction, its value is -1
        
        // If we can't make any move, break out
        if (right == -1 && diagonal == -1 && bottom == -1) {
            break;
        }
        
        // Choose the maximum value direction
        if (right >= diagonal && right >= bottom && right != -1) {
            j++; // Move right
            sum += matrix[i][j];
        } else if (diagonal >= right && diagonal >= bottom && diagonal != -1) {
            i++; // Move diagonal
            j++;
            sum += matrix[i][j];
        } else if (bottom >= right && bottom >= diagonal && bottom != -1) {
            i++; // Move bottom
            sum += matrix[i][j];
        }
    }
    
    cout << sum << endl;
    return 0;
}
