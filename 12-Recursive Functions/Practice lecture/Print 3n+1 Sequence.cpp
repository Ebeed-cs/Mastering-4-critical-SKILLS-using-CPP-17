#include <iostream>
using namespace std;


void sequence(int n)
{
    cout << n << " ";
    if(n == 1)
        return;
    else if( n % 2 == 0)
        sequence(n / 2);
    else
        sequence( 3 * n + 1 );
}


int main() {
    int n;
    cin >> n;
    sequence(n);
    return 0;
}
