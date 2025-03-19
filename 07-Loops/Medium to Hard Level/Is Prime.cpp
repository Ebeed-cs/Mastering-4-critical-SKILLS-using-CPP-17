#include<iostream>
#include <cmath>
using namespace std;
/*
							 Is Prime?
 
		● Read an integer N (< 500) and print YES if it is prime, otherwise NO
 			○ A prime number is greater than 1 AND cannot be formed by multiplying two smaller numbers. 
				■ In other words, number%whatever != 0
				■ The first few prime numbers are 2, 3, 5, 7, 11, 13, 17, 19, 23, and 29.

		● Input ⇒ Output 
			○ 13 ⇒ YES           (only 1 * 13)
			○ 12 ⇒ NO             (E.g. 12 = 2 *6, so 12 can be divided by 2 or 6)




*/

int main() {
	int N;
	cin >> N;
	bool is_prime = true;
	if(N <= 1)
		cout << "NO" <<endl;
	else
	{
		for(int i = 2 ; i <= sqrt(N) ; ++i )
		if( N % i == 0)
		{
			is_prime = false;
			break;
		}
		if(is_prime)
			cout << "Yes" << endl;
		else 
			cout << "No" << endl;
	}			

	return 0;
}

/*
	the original divisions to a number be between 2 : root(number)
*/
