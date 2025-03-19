#include <iostream>
using namespace std;

/*
            Max value

        ● Read 2 integers for the rows and columns of a matrix ( <= 100). Then read rows x cols integer value. Find the position of maximum value in the array. If there are several ones, find the last occurance

        ● Input:
            ○ 3 4
            ○ 1 5 1 10
            ○ 2 10 3 4
            ○ 1 10 10 7
        ● Output
            ○ Max value at position 2 2 with value = 10
*/

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
