#include <iostream>
using namespace std;
/*
        Power function

    ● int my_pow(int value, int p = 2)
    ● Return value * value ….. * value p times
    ● E.g. my_pow(7, 3) = 7 * 7 * 7 = 343
    ● Note: if p = 0, answer is 1

*/

int my_pow(int value, int p = 2) {
    if (p == 0) return 1;
    return value * my_pow(value, p - 1);
}

int main() {
    cout << my_pow(7) << endl;
    return 0;
}

/*
    note here the default value to the base is '2' which is the common base if you don't specify else
*/
