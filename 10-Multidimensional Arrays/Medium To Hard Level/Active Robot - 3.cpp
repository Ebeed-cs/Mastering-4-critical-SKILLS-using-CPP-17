#include <iostream>
using namespace std;

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
