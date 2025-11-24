#include<iostream>
using namespace std;


int main() {
	int x, result = 1;
	cin >> x;
	while (--x)
	{
		if (++result % 3 == 0)
			cout << result << " ";
	}
	return 0;
}
