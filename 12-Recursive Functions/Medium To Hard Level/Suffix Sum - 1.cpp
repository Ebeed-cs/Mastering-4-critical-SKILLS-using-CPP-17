#include <iostream>
using namespace std;


int sufix_sum(int arr[], int len, int sum_last_N = 0) {
    if (sum_last_N)
        return sufix_sum(arr + len - sum_last_N, sum_last_N, 0);
    else {
        if (len == 1) return arr[0];
        return arr[0] + sufix_sum(arr + 1, len - 1);
    }
}

int main() {
    int arr[] = { 1, 3, 4, 6, 7 };
    int len = sizeof(arr) / sizeof(arr[0]);

    cout << sufix_sum(arr, len, 3) << endl;

    return 0;
}
