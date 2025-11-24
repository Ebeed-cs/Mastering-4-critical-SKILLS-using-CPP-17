#include<iostream>
using namespace std;


int main() {
	int x;
	cin >> x;
	int count = x - 1;

	while (count >= 0)
	{
		int print_s = x - count;
		while (print_s > 0)
		{
			cout << "*";
			print_s--;
		}
		cout << endl;
		count--;
	}
	return 0;
}
