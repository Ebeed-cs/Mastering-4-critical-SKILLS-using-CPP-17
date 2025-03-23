#include <iostream>
using namespace std;
/*
        Array sum

    ● Int sum(int arr[], int len);
    ● Write a function that computes array sum
    ● Input 1, 8, 2, 10, 3 ⇒ 24

*/

int arr_sum(int arr[], int len) {
    if (len == 1) return arr[0];
    return arr[0] + arr_sum(arr + 1, len - 1); // the returned arr will be decremented by one element ex: before call arr = [1 , 8 , 2 , 10 , 3] after will be [8 , 2, 10 , 3] and we adjust the count of len up on that 
}

int main() {
    int arr[] = { 1, 8, 2, 10, 3 };
    cout << arr_sum(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
