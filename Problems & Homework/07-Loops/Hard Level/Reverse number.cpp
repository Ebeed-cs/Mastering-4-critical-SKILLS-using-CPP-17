#include<iostream>
using namespace std;

/*
							Reverse number
	● Read an integer N, then find its reverse integer R
		○ Print R R*3
	● input ⇒ Output
		○ 123  ⇒ 321 963



*/

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
