#include <iostream>
using namespace std;

int arr_max(int arr[], int len) {
    if (len == 1) return arr[0];
    int max_rest = arr_max(arr + 1, len - 1);
    return (arr[0] > max_rest) ? arr[0] : max_rest;
}

int main() {
    int arr[] = { 1 , 50 , 2 , 10 , 19 , 2 , 100 };
    cout << arr_max(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
