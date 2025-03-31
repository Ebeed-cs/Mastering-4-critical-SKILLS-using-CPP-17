#include <iostream>
using namespace std;
/*
        Print a traingle (v1)

    5
    *****
    ****
    ***
    **
    *
*/

void draw_traingle(int n)
{
    if (n == 1)
    {
        cout << "*";
        return;
    }
    int count = n;
    while (count--)
        cout << "*";
    cout << endl;
    draw_traingle(n - 1);
}

int main() {
    int n;
    cin >> n;
    draw_traingle(n);
    return 0;
}
