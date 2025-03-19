#include<iostream>
using namespace std;
/*									Approach 1

				Triples of numbers

	● Read N, M, W. Find all triples that has A + B <= C where 
		○ 1 <= A <= N 
		○ A <= B <= M	
		○ 1 <= C <= W


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
