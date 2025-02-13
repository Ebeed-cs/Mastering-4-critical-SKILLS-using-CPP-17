#include<iostream>
using namespace std;

/*
			Special Sum

	● Read integer T for number of test cases.
	● For each test case read integer N. Then read N integers a, b, c
	● Output: Compute the sum of the following expression:
		○ a, b*b, c*c*c, d*d*d*d, e*e*e*e*e……
			■ That is the k-th number is repeated k times

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
	while (T)
	{
		int N, sum, count, temp;
		sum = count = 0;
		cin >> N;
		while (count < N)
		{
			int num, i;
			cin >> num;
			i = ++count;
			temp = 1;
			while (i > 0)
			{
				temp *= num;
				i--;
			}
			sum += temp;
		}
		cout << sum << endl;
		T--;
	}
	return 0;
}

/*
	the first  -> print one time
	the second -> print two times
	the third  -> print three times
	the fourth -> print fourth times
			and so on

	We need 3 nested loops
		loop over test cases
		loop over reading numbers
		loop to repeat the number K times (multiplication)
*/
