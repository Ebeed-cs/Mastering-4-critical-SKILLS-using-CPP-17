#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int nth_prime(int m) {
    int i = 2;
    while (m)
        if (is_prime(i++))
            m--;
    return --i;
}
int main() {
    for (int i = 1; i <= 8; ++i)
        cout << nth_prime(i) << " ";
    return 0;
}
