#include<iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	if(num < 10000)
		cout << "this is a small number" << endl;
	else	
	{
		int digit1 , digit2 , digit3;
		int sum = 0;
		digit1 = num % 10;
		num /= 10;
		digit2 = num % 10;
		num /= 10;
		digit3 = num % 10;
		sum = digit1 + digit2 + digit3;
		if(sum % 2 != 0)
			cout << "this is a greater number" << endl;
		else
			if((digit1 % 2 != 0) || 
			   (digit2 % 2 != 0) ||
			   (digit3 % 2 != 0))
					cout << "this is a good number" << endl;
			else	
					cout << "this is a bad number" << endl;
	}
	return 0;
}

/*
	test cases : 
		500 -> this is a small number
		11511 -> this is a greater number
		11310 -> this is a good number
		11400 -> this is a bad number

*/
