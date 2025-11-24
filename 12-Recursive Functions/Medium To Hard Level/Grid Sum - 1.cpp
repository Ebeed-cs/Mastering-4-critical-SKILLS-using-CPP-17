#include <iostream>
using namespace std;

int di[] = { 0 , 1 ,1 };
int dj[] = { 1 , 1, 0 };

bool check(int& i, int& j, int ROWS, int COLS, int grid[][100]) {
	bool end = true;
	int max_i, max_j;
	max_i = i;
	max_j = j;
	for (int k = 0; k < 3; ++k) {
		int new_i = i + di[k];
		int new_j = j + dj[k];
		if (new_i >= ROWS ||
			new_j >= COLS)
			continue;
		if (end) {
			max_i = new_i;
			max_j = new_j;
			end = false;
		}
		if (grid[max_i][max_j] < grid[new_i][new_j])
			max_i = new_i, max_j = new_j;
	}
	i = max_i, j = max_j;
	return end;
}

int path_sum(int grid[100][100], int row, int col, int ROWS, int COLS) {
	if (check(row, col, ROWS, COLS, grid)) return grid[0][0];
	return grid[row][col] + path_sum(grid , row , col , ROWS , COLS);
}

int main() {
	int ROWS, COLS;
	cin >> ROWS >> COLS;
	int grid[100][100];
	for (int i = 0; i < ROWS; ++i)
		for (int j = 0; j < COLS; ++j)
			cin >> grid[i][j];
	cout << path_sum(grid, 0, 0, ROWS, COLS) << endl;
	return 0;
}


/*

3 3
1 0 0
0 2 0
0 0 3
6[output]

5 1
1 2 3 4 5
15[output]

1 5
1 2 3 4 5
15[output]

1 1
5
5[output]

3 3
1 7 8
2 10 11
20 5 9
31[output]

 */

