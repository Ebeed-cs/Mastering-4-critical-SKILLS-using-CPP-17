#include<iostream>
using namespace std;
					// Approach 1

int main() {
	int N, M, sum , count = 0;
	cin >> N >> M >> sum;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (i + j == sum)
				count ++;
	
	cout << count << endl;
	return 0;
}
