#include<iostream>
using namespace std;

/*
			Print face down left angled triangle
 ● Read integer N, then print a face down left angled triangle that has N rows
		as below : 
			6
			******
			*****
			****
			***
			**
			*
*/

int main() {
	int x;
	cin >> x;

	while (x > 0)
	{
		int print_s = x ;
		while (print_s > 0)
		{
			cout << "*";
			print_s--;
		}
		cout << endl;
		x--;
	}
	return 0;
}
