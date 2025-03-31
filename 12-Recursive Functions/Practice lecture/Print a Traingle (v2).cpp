#include <iostream>
using namespace std;
/*
        Print a traingle (v2)

    5
    *
    **
    ***
    ****
    *****
*/

void draw_traingle(int n)
{
    if (n == 0) {
        return;
    }
    draw_traingle(n - 1);
    int count = n;
    while (count--)
        cout << "*";
    cout << endl;
}

int main() {
    draw_traingle(5);
    return 0;
}
