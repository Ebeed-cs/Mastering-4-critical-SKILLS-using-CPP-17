#include <iostream>
using namespace std;
/*
               Flatten 3D Array

    ● Then read integer either 1 (convert 3D to 1D) or 2 (1D to 3D)
    ● If input was 1, then read 3 integers d, r, c then convert to position in 1D array
    ● If input was 2, then read 1 integer position, then convert to 3D array position
    ● Try to generalize if we have e.g. 6D array

    ● Input ⇒ Outputs
        ○ 3 4 5 1 1 0 0 ⇒ 20
        ○ 3 4 5 2 20 ⇒ 1 0 0
        ○ 3 4 5 1 1 1 1 ⇒ 26
        ○ 3 4 5 1 2 3 2 ⇒ 57
        ○ 3 4 5 1 2 0 0 ⇒ 40
        ○ 3 4 5 2 59 ⇒ 2 3 4

*/

int dep, row, col;
    cin >> dep >> row >> col;
    
    // Pre-compute the size of a 2D slice for more efficiency
    int slice_size = row * col;
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        int d, i, j;
        cin >> d >> i >> j;
        
        // Compute the 1D index in a single expression
        int index = d * slice_size + i * col + j; // (i * col + j) -> index of 1D array
        cout << index;
    }
    else {
        int index;
        cin >> index;
        
        // More efficient calculation using pre-computed slice size
        int d = index / slice_size;
        int remainder = index % slice_size;
        int i = remainder / col;
        int j = remainder % col;
        
        cout << d << " " << i << " " << j;
    }
    
    return 0;
}
