#include<iostream>
#include <cmath>
using namespace std;

/*
							Print Primes

	● Read integer N (<500), then print all prime numbers <= N
		○ Output should be comma separated, as below
			■ Don’t print comma after the last number
	● Input ⇒ Output
		○ 18 ⇒ 2,3,5,7,11,13,17
			■ No comma after last number!


*/

int main() {
	int N;
	cin >> N;
	bool is_prime = true;
	if (N > 2)
		cout << 2;

	for (int i = 3; i <= N; i += 2)
	{
		for (int j = 2; j*j<= i ; ++j)
		{
			if ((i % j) == 0)
			{
				is_prime = false;
				break;
			}
		}
		if (is_prime)
			cout << " ," << i;
		is_prime = true;
	}


	return 0;
}

/*
	all the prime numbers are odd numbers except number '2'
	Using i * i <= N instead of i <= sqrt(N)
*/
