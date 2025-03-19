#include<iostream>
using namespace std;

/*

				Special Sum
	● Read T for number of test cases. For each test case read integer N: number
		of numbers. Then read N numbers a, b, c, ….. and compute the sum of:
		○ (a, b*b, c*c*c, d*d*d*d, e*e*e*e*e……)
		○ That is the k-th number is repeated k times

	● Input:
		○ 2
		○ 3   5 7 2
		○ 4  1 2 3 4
	● Output
		○ 62                                         [as (5 + 7*7 + 2*2*2)  = 62]
		○ 288                                       [as (1+2*2+3*3*3+4*4*4*4) = 288]


*/

int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N, num, temp , sum = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			cin >> num;
			temp = 1;
			for(int j = i ; j > 0 ; j--)
				temp *= num;
			sum += temp;
		}
		cout << sum << endl;
	}

	return 0;
}
