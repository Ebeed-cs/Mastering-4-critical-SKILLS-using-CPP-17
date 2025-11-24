#include<iostream>
#include <cmath>
using namespace std;

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
