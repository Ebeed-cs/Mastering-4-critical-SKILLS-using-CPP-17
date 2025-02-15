#include<iostream>
using namespace std;
/*									Approach 2

			Fibonacci Sequence
 
		● A popular math sequence
			○ First 2 numbers: 0 1
			○ Then each number is sum of last 2 numbers: 
				■ 0 1 1 2 3 5 8 13 21 34 
		● E.g. 13 = 5 + 8
 		● E.g. 34 = 13+21


*/

int main() {
	int N;
	cin >> N;
	for(int a = 0 , b = 1 , c = -1 , i = 0; 
		i < N ;
		 c = a + b , a = b , b = c , ++i )
		cout << a << " ";
	return 0;
}
