#include<iostream>
using namespace std;


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
