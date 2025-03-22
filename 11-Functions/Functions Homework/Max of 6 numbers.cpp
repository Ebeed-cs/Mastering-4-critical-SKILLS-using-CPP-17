#include <iostream>
using namespace std;
/*
             Max of 6 numbers

    ● Write a function that reads 6 numbers and compute their maximum. Create the following functions
        ○ max(int a, int b, int c)
        ○ max(int a, int b, int c, int d)
        ○ max(int a, int b, int c, int d, int e)
        ○ max(int a, int b, int c, int d, int e, int f)
    ● How can
        ○ max(int a, int b, int c, int d) utilize max(int a, int b, int c) ? and so on
*/

int max(int a, int b) {
    if (a >= b)
        return a;
    return b;
}

int max(int a, int b, int c) {
    return max(max (a, b), c);
}

int max(int a, int b, int c, int d) {
    return max(max(a, b, c), d);
    // return max(max(max(a, b), c), d);
}

int max(int a, int b, int c, int d, int e) {
    return max(max(a, b, c, d), e);
    // return max(max(max(max(a, c), c), d), e);
}

int max(int a, int b, int c, int d, int e, int f) {
    return max(max(a, b, c, d, e), f);
    // return max(max(max(max(max(a, b), c), d), e), f);
}

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    cout << max(a, b, c, d, e, f) << endl;
    return 0;
}
