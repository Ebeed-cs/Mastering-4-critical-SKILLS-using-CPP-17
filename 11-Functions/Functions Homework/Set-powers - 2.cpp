#include <iostream>
using namespace std;

int power(int base, int pow) {
    int result = base;
    if (!pow)
        return 1;
    for (int i = 0; i < pow - 1; ++i) {
        result *= base;
    }
    return result;
}

void set_powers(int arr[] , int len = 5, int m = 2){
    for(int i = 0; i < len; ++i)
        arr[i] =  power(m , i);
}

int main() {
    int len, m;
    int arr[100];
    cin >> len >> m;
    set_powers(arr , len , m);
    
    for(int i = 0; i < len; ++i)
        cout << arr[i] << " ";
    return 0;
}
