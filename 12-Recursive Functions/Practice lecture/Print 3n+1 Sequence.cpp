#include <iostream>
using namespace std;
/*
        Print 3n+1 Sequence

    ● A 3n+1 goes as following
    ● Start from a number n
    ● If this number is even, next number in sequence is n / 2
    ● If this number is odd, next number in sequence is 3 * n + 1
    ● If this number is 1 = end of sequence
    ● E.g. Start from 5: 5 16 8 4 2 1
    ● E.g. Start from 6: 6 3 10 5 16 8 4 2 1
    ● E.g. Start from 7: 7 22 11 34 17 52 26 13 40 20 10 5 16 8 4 2 1
    ● Write a recursive function to print it

*/

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
