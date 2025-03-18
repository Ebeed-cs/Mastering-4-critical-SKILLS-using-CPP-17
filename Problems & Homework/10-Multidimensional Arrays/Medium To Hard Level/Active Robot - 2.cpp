#include <iostream>
using namespace std;
/*
                Active Robot - 2

    ● Read integers N, M represents a matrix. A robot start at cell (0, 0).
    ● Read integer K, then K commands. Each command is 2 values
        ○ Direction from 1 to 4: up, right, down, left
        ○ Steps: a number to number steps to take in the direction. Steps [1, 1000000000]
        ○ If the robot hits the wall during the move, it circulates in the matrix.
        ○ For every command, print where is the robot now

    ● Input
        ○ 3 4  4   2 1   3 2   4 2   1 3
            ■ 2 1 means to right 1 step - 3 2 means down 2 steps
    ● Output
        ○ (0, 1) (2,1) (2, 3) (2, 3)

*/

int main() {
    int row, col;
    cin >> row >> col;
    int i = 0, j = 0;

    int Q;
    cin >> Q;
    for (int query = 0; query < Q; ++query) {
        int direction, steps;
        cin >> direction >> steps;

        if (direction == 1) {  // Up
            // Calculate new position using modulo
            i = (i - (steps % row) + row) % row;
        }
        else if (direction == 2) {  // Right
            j = (j + (steps % col)) % col;
        }
        else if (direction == 3) {  // Down
            i = (i + (steps % row)) % row;
        }
        else {  // Left
            j = (j - (steps % col) + col) % col;
        }

        cout << "(" << i << ", " << j << ")" << endl;
    }

    return 0;
}
