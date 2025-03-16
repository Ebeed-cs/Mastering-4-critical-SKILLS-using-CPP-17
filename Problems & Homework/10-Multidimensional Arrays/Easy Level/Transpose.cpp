#include <iostream>
using namespace std;

/*
                Transpose

    ● Read integers N, M, then Read matrix NxM. Compute another array, the transpose

    3 4
    8 16 9 52
    3 15 27 6
    14 25 29 10

    output
    8 3 14
    16 15 25
    9 27 29
    52 6 10

*/

int main() {
	int arr1[100][100];
	int arr2[100][100];
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> arr1[i][j];

	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			arr2[j][i] = arr1[i][j]; // when you put the col 'j' instead of row 'i' and vise verse that give the round the matrix

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j)
			cout << arr2[i][j] << " ";
		cout << "\n";
	}

	return 0;
}
