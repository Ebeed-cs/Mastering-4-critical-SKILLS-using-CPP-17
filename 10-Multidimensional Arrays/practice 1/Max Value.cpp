#include <iostream>
using namespace std;


int main() {
    int row, col;
    int max_index;
    cin >> row >> col;
    max_index = row * col;

    int input, ind;
    int max = INT_MIN;
    for (int i = 0; i < max_index; ++i)
    {
        cin >> input;
        if (max <= input)
        {
            max = input;
            ind = i;
        }
    }

    cout << "max value at position " << ind / col << " " << ind % col << " with value = " << max;



    return 0;
}
