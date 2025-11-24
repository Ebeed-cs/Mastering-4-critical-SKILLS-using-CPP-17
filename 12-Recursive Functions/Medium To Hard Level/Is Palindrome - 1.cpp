#include <iostream>
using namespace std;


bool isPalindromeRecursive(int arr[], int start, int end) {
	// Base case: empty array or single element is palindrome
	if (start >= end) {
		return true;
	}

	// If first and last elements don't match, not palindrome
	if (arr[start] != arr[end]) {
		return false;
	}

	// Recursively check the subarray without the matched pair
	return isPalindromeRecursive(arr, start + 1, end - 1);
}

// Wrapper function to make the recursive call cleaner
bool isPalindrome(int arr[], int size) {
	return isPalindromeRecursive(arr, 0, size - 1);
}

int main() {
	int arr[] = { 1 , 2 , 5, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << isPalindrome(arr, len) << endl;

	return 0;
}

