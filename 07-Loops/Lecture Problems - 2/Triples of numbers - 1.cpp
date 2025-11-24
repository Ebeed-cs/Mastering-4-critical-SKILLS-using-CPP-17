#include<iostream>
using namespace std;
/*									Approach 1



*/

int main() {
	int N, M, W, count = 0;
	cin >> N >> M >> W;
	for (int i = 1; i <= N; i++)
		for(int j = i; j <= M; ++j) // j : i -> M
			for(int k = 1 ; k <= W; ++k)
				if(i + j <= k)	
					count ++;

	cout << count << endl;
	return 0;
}
