#include<iostream>
using namespace std;


int main() {
	int num, pow, result = 1;
	cin >> num >> pow;
	while (pow >= 1)
	{
		result *= num;
		--pow;
	}
		cout << result << endl;
	return 0;
}
