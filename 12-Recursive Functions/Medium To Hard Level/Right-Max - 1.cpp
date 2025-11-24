#include <iostream>
using namespace std;

void right_max(int arr[], int len, int start_position = 0) {
    if (start_position)
        right_max(arr + start_position, len - start_position, 0);
    else {
        if (len == 1) return;
        arr[len - 2] = max(arr[len - 1], arr[len - 2]);
        right_max(arr, len - 1);
    }

}

int main() {
    int arr[] = { 1, 8, 10, 3, 50 };
    int len = sizeof(arr) / sizeof(arr[0]);
    right_max(arr, len);
    for (int i = 0; i < len; ++i) cout << arr[i] << " ";
    return 0;
}
