#include <iostream>
using namespace std;

int main() {
    int A, B;
    cin >> B >> A;
    int b_1 = A * A;
    int b_2 = 2 * A + 1;
    cout << (B + 1) / 2 * (b_1)+(-B + 1) / 2 * (b_2);
    return 0;
}


