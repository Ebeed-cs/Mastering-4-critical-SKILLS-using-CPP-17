#include<iostream>
using namespace std;

int main() {
	int N, count = 0;
	int i = 0;
	cin >> N;
	while (N)
	{
		count += 3;
		if (!(count % 4 == 0))
			N--, cout << count << " ";
	}
	return 0;
}
