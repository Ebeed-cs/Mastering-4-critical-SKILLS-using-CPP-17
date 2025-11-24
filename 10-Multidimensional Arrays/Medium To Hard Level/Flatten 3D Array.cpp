#include <iostream>
using namespace std;


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
