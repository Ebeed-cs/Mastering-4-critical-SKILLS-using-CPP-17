#include<iostream>
using namespace std;

/*

		Minimum of values
 ● Input: Read integer T for a number of test cases. 
 ● For each test case read integer N followed by reading N integers. 
 ● Output: For each test case, print the minimum of the N integers.
 
 ● Input
 	○ 2    6   10 50 20 70 30 4         3 10 5 30
 	○ Notice here we have 2 test cases
	 	■ 6     10 50 20 70 30 4 
		■ 3      10 5 30
 ● Output
	○ 4
 	○ 5

*/

int main() {
	int T , N , input , min_num;
	cin >>T;
	while(T--)
	{
		min_num = INT_MAX;
		cin >> N;

		while(N > 0)
		{
			cin >> input;
			if(input < min_num)
				min_num = input;
			N --;
		}

		cout << min_num << endl;
	}
	return 0;
}

