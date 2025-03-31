#include <iostream>
using namespace std;
/*
        Suffix Sum - 2

    ● Write a function that sums only the last N elements in an array.
    ● Define its signature
    ● Input [1, 3, 4, 6, 7], 3 ⇒ 17 (4+6+7)

*/

int sufix_sum(int arr[], int len, int cnt) {
	if (cnt == 0)
		return 0;

	return arr[len - 1] + sufix_sum(arr, len - 1, cnt - 1);
}

int main() {
	int arr[] = { 1, 8, 2, 10, 3 };

	cout << sufix_sum(arr, 5, 3);

	return 0;
}

