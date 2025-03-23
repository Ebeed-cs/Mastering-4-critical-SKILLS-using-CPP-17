#include <iostream>
using namespace std;
/*
        Array average

    ● double average(int arr[], int len);
    ● Write a function that computes array average
        ○ Don’t divide by length in the main
    ● Input 1, 8, 2, 10, 3 ⇒ 4.8

*/

double average(int arr[], int len) {
    // Base case
    if (len == 1) return arr[0];
    
    // Calculate sum using recursion
    double sum = arr[0] + (len - 1) * average(arr + 1, len - 1); 
    
    // Return the average
    return sum / len;
}

int main() {
    int arr[] = { 1, 8, 2, 10, 3 };
    cout << average(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}

/*
    we multible by (len - 1) to regardless the divide by average until the final return will not regardless
*/
