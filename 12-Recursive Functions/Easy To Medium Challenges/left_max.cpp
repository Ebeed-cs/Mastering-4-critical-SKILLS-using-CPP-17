#include <iostream>
using namespace std;
/*
        Left-Max

    ● Given array, change each element at position i to be the maximum of numbers from 0 to index i
    ● E.g. input 1 3 5 7 4 2 ⇒ [1, 3, 5, 7, 7, 7]
    ● Void left_max(int arr[], int len);

*/
void left_max(int arr[], int len) {
    if (len == 1) return;
    left_max(arr, len - 1);
    arr[len-1] = max(arr[len-1], arr[len-2]);
    
    // arr[len - 1] = (arr[len - 1] > arr[len - 2]) ? arr[len - 1] : arr[len - 2];
    
}

int main() {
    int arr[] = { 1 ,3 ,5 ,7 ,4 ,2 };
    int len = sizeof(arr) / sizeof(arr[0]);
    left_max(arr, len);
    for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    return 0;
}
