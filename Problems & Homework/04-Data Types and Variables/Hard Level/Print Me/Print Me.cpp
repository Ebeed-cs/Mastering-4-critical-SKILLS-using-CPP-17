#include <iostream>
using namespace std;
/*
Print Me


Write a program that reads 2 integers A, B
    B is either -1 or 1
If -1, print 2*A+1
If 1, print A*A

*/
int main() {
    int A, B;
    cin >> B >> A;
    int b_1 = A * A;
    int b_2 = 2 * A + 1;
    cout << (B + 1) / 2 * (b_1)+(-B + 1) / 2 * (b_2);
    return 0;
}


