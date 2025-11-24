#include <iostream>
#include <climits>
using namespace std;

int main() {
    // cout << INT_MAX << endl;     // 2147483647
    int N;
    cin >> N;
    cout << (N * (N + 1)) / 2 << endl;
    return 0;
}

/* 
    to reach the overflow value, the value of N will be either
    : 65535.5 or -65536.5
    and ensure the data type of the N variable is long long'
    to not overflow and show the real value
*/


