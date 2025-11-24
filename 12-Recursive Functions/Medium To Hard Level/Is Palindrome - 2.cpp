#include <iostream>
using namespace std;


bool isPalindrome(int arr[], int len) {
    if (len <= 1) return true;

    if (arr[0] != arr[len - 1]) return false;

    return isPalindrome(arr + 1, len - 2);
}

int main() {
	int arr[] = { 1 , 2 , 2, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	cout << isPalindrome(arr, len) << endl;

	return 0;
}
