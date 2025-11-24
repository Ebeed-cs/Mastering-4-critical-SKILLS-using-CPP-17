#include <iostream>
using namespace std;


int main()
{
	int N, i, count, col;
	count = 0;
	bool decrement = false;
	cin >> N;
	int down = N - 2;
	while (count < 2 * N)
	{

		if (!decrement)
			i = count;
		count++;

		if (decrement)
		{
			i = down--;
		}

		if (N == i)
		{
			i = count - 2;
			decrement = true;
		}

		col = N * 2 - 1;
		while (col > 0)
		{
			if (N - i <= col && col <= N + i)
				cout << "*";
			else
				cout << " ";
			col--;
		}
		cout << endl;
	}
	return 0;
}
