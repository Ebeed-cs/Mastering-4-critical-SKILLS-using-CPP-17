#include <iostream>
using namespace std;
/*
        Length of 3n+1

    ● Implement 3n+1 function to compute the length of the sequence
    ● int length_3n_plus_1(int n)
    ● E.g. length_3n_plus_1(6) ⇒ 9

*/


int length_3n_plus_1(int n) {
    if (n == 1)
        return 1;
    else if (n % 2 == 0)
        return 1 + length_3n_plus_1(n / 2);
    else
        return 1 + length_3n_plus_1(3 * n + 1);
}

int main() {
    cout << length_3n_plus_1(6);
    cout << length_3n_plus_1(1);
    return 0;
}
