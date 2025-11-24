#include <iostream>
using namespace std;

    // MY SOLUTION USING ONLY THREE VARIABLES 
int main() {
   int a = 115, b = 20 , c = 301;
   a = a + b + c;
   c = a - b - c;
   b = a - c - b;
   a = a - c - b;
   cout << a << " " << b  << " " << c;
    return 0;
}

