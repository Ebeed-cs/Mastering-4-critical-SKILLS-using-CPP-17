#include<iostream>
#include <cmath>
using namespace std;

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
