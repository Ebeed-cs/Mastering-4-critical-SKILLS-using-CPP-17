#include <iostream>
using namespace std;


int my_pow(int value, int p = 2) {
    if (p == 0) return 1;
    return value * my_pow(value, p - 1);
}

int main() {
    cout << my_pow(7) << endl;
    return 0;
}

/*
    note here the default value to the base is '2' which is the common base if you don't specify else
*/
