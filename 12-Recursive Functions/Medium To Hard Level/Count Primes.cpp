#include <iostream>
#include<cmath>
using namespace std;

bool is_prime(int num, int divisor) {
    // Base cases
    if (divisor > sqrt(num)) return true;  // No divisors found
    if (num <= 1) return false;  // 1 and below are not prime
    if (num == 2) return true;   // 2 is prime
    if (num % divisor == 0) return false;  // Divisible, not prime
    
    // Recursive call with next divisor
    return is_prime(num, divisor + 1);
}

int count_primes(int start, int end) {
    // Base case: if start exceeds end, return 0
    if (start > end) return 0;
    
    // Recursive logic to count primes
    int prime_count = count_primes(start + 1, end);
    
    // Check if current number is prime and increment count
    if (is_prime(start, 2)) {
        prime_count++;
    }
    
    return prime_count;
}

int main() {
    // Test cases
    int result2 = count_primes(15, 20);
    int result3 = count_primes(10, 5000000);
    
    cout << result2 << " ";
    cout << result3 << " ";
    
    return 0;
}
