#include <iostream>
using namespace std;


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
