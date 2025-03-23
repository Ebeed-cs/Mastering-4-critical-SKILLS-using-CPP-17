#include <iostream>
using namespace std;
/*
        Array Increment

    ● void array_increment(int arr[], int len)
    ● The function increments each arr[i] with i
    ● E.g. for input
        ○ [1, 2, 5, 9] it be [1+0, 2+1, 5+2, 9+3]
        ○ 1 8 2 10 3 ⇒ 1 9 4 13 7

*/

void array_increment(int arr[], int len) {
    if (len == 0) return;
    arr[len - 1] += (len - 1);
    array_increment(arr, len - 1);
}

int main() {
    int arr[] = { 1, 8, 2, 10, 3 };
    int len = sizeof(arr) / sizeof(arr[0]);
    array_increment(arr, len);
    for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    return 0;
}
