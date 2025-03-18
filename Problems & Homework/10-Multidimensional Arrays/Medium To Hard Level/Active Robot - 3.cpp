#include <iostream>
using namespace std;
/*
                Active Robot - 3

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

    int di[] = { -1 , 0 , 1 , 0 };
    int dj[] = { 0 , 1 , 0 , -1 };

    int Q;
    cin >> Q;

    for (int query = 0; query < Q; ++query) {
        int direction, steps;
        cin >> direction >> steps;
        direction--;

        i = (i + di[direction] * steps) % row;
        j = (j + dj[direction] * steps) % col;

        if (i < 0)
            i += row;
        if (j < 0)
            j += col;


        cout << "(" << i << ", " << j << ")" << endl;
    }

    return 0;
}
