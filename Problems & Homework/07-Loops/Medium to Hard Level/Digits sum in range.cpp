#include<iostream>
#include <cmath>
using namespace std;

/*

					Digits sum in range

	● Read three numbers N, A, B. Print the summation of the numbers between 1 and N whose sum of digits is between A and B(inclusilve).
	● Input / Output
		○ 20 2 5 ⇒ 84
			■ Numbers whose sums of digits are between 2 and 5, are: 2,3,4,5,11,12,13,14, 20.
	● E.g. digits sum of 13 is 4 : which is between (2, 5)
		○ 10 1 2 ⇒ 13
		○ 100 4 16 ⇒ 4554


*/

int main() {
	int N, A, B, result = 0;
	cin >> N >> A >> B;
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		int num = i;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum >= A && sum <= B)
			result += i;
		sum = 0;
	}
	cout << result << endl;

	return 0;
}

