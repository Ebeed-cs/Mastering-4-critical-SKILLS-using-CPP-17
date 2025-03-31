#include <iostream>
using namespace std;
/*
        Right-Max - 2

    ● Given array, change each element at position i to be the maximum of numbers from index i to end of array
    ● E.g. input 1 3 5 7 4 2 ⇒ [7, 7, 7, 7, 4, 2]
    ● Void right_max(int arr[], int len, int start_position = 0);

*/

void right_max_v1(int arr[], int len, int start_pos = 0) {
	if (start_pos == len - 1)
		return;

	right_max_v1(arr, len, start_pos + 1);
	arr[start_pos] = max(arr[start_pos], arr[start_pos + 1]);
}

void right_max_v2(int arr[], int len) {
	if (len == 1)
		return;

	right_max_v2(arr + 1, len - 1);	// arr+1 is the a new array shifted. E.g. { 1, 8, 2, 10, 3 } => {8, 2, 10, 3 }
	arr[0] = max(arr[0], arr[1]);	// Then we only need to think about arr (0)
}

int main() {
	int arr[] = { 1, 8, 2, 10, 50 };

	right_max_v1(arr, 5, 2);

	for (int i = 0; i < 5; ++i) {
		cout << arr[i] << " ";
	}

	return 0;
}
