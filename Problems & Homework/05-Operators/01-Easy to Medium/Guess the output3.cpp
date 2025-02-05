#include<iostream>
using namespace std;

/*
    Guess the output3
*/

int main() {
    int i = 0;
    cout << i << " " << ++i << endl; // 0 1
    // Undefined Behavior until C++17
    return 0;
}
