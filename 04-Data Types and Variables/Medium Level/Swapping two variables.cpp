#include <iostream>
using namespace std;

int main() {
   int num1 = 7 , num2 = 231;
   num2 = num2 + num1;
   num1 = num2 - num1;
   num2 = num2 - num1;
   cout << num1 << " " << num2;
    return 0;
}

