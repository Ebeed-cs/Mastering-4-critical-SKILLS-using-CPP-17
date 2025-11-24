#include <iostream>
using namespace std;


int arr[100] = { 1 , 1 };

int fibonacci(int n) {
	if (arr[n]) return arr[n];
	return arr[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

/*
	dynamic programming 
		up function used only n nodes while the below use 2^(n + 1) nodes
*/
int fib(int n) {
	if (n <= 1)
		return 1;

	return fib(n - 1) + fib(n - 2);
}

int main() {
	cout << fibonacci(50);
	return 0;
}
