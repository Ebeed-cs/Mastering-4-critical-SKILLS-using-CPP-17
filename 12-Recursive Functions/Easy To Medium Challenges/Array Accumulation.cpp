#include <iostream>
using namespace std;

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
