#include <iostream>
using namespace std;
/*
					 Fibonacci

	● Implement fibonacci: Int fibonacci(int n)
		○ Recall fibonacci sequence: 1 1 2 3 5 8 13 21 35
		○ E.g. fibonacci(6) = 13
		○ Recall that: fibonacci(n) = fibonacci(n-1) + fibonacci(n-2). E.g. fib(6) = fib(5)+fib(4) = 13
			■ So it calls 2 subproblems of its type
	● Can u compute fibonacci(40)? fibonacci(50)? Why? Any work around? Hint: Array

*/

int arr[100] = { 1 , 1 };

int fibonacci(int n) {
	if (arr[n]) return arr[n];
	return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int fib(int n) {
	if (n <= 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int main() {
	cout << fibonacci(50);
	return 0;
}
