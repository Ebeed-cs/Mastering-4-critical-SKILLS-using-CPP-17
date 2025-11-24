#include <iostream>
using namespace std;


int arr_max(int arr[], int len) {
    if (len == 1) return arr[0];
    int max = arr_max(arr, len - 1);
    return (max > arr[len - 1])? max : arr[len - 1];
}

int main() {
    int arr[] = { 1 , 50 , 2 , 10 , 19 , 2 , 100 };
    cout << arr_max(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
