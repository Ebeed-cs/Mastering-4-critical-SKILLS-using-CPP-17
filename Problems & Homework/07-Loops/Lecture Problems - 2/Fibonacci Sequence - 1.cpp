#include<iostream>
using namespace std;
/*									Approach 1

			Fibonacci Sequence
 
		● A popular math sequence
			○ First 2 numbers: 0 1
			○ Then each number is sum of last 2 numbers: 
				■ 0 1 1 2 3 5 8 13 21 34 
		● E.g. 13 = 5 + 8
 		● E.g. 34 = 13+21


*/

int main() {
	int N , num1 = 0 , num2 = 1;
	cin >> N;
	cout << num1 << " " << num2 << " ";
	for( int i = 2 ; i < N ; i++) // i : 2 -> N 'beacouse we have already printed first two terms '0 1'
	{
		int result = num1 + num2;
		num1 = num2;
		num2 = result;
		cout << result << " ";
	}
	return 0;
}
