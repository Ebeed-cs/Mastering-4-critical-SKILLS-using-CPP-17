#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int number[N];
	for (int i = 0; i < N; ++i)
		cin >> number[i];

	for (int i = 0; i < N / 2; ++i)
	{
		number[i] = number[i] + number[N - i - 1];
		number[N - i - 1] = number[i] - number[N - i - 1];
		number[i] = number[i] - number[N - i - 1];
	}

	for (int i = 0; i < N; ++i)
		cout << number[i] << " ";
	return 0;
}
