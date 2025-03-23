#include <iostream>
using namespace std;
/*
        Array Accumulation

    ● Given an array we want to accumulate it as following:
        ○ Input 1 2 3 4 5 6
        ○ Output array
            ■ 1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5, 1+2+3+4+5+6
            ■ 1, 3, 6, 10, 15, 21
        ○ That is return arr[i] = sum of all numbers from 0 to i
    ● void accumulate_arr(int arr[], int len);
        ○ Input 1 8 2 10 3 ⇒ 1 9 11 21 24

*/
void accumulate_arr(int arr[], int len) {
    if (len == 1) return;
    accumulate_arr(arr , len - 1);
    arr[len - 1] += arr[len - 2];
}

int main() {
    int arr[] = { 1, 8, 2, 10, 3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    accumulate_arr(arr, len);
    for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    return 0;
}
