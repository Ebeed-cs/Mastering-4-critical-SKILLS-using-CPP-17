#include <iostream>
using namespace std;
/*
Swapping 3 numbers!

Write a code to swap 3 numbers
Let say we have numbers a = 115, b = 20, c = 301
We wanna their final values to be: a = 20, b = 301, c = 115

*/
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

