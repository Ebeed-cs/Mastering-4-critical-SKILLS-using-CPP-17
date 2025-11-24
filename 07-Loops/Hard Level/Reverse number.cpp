#include<iostream>
using namespace std;


int main() {
	int N , result = 0;
	cin >> N;
	while (N > 0)
	{
		result = result * 10 + (N % 10);
		N /= 10;
	}
	cout << result << " " << result * 3 << endl;
	return 0;
}
