#include<iostream>
using namespace std;


int main() {
	int N, max_num = INT_MIN;
	cin >> N;
	int number[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		if (number[i] > max_num)
			max_num = number[i];
	}
	cout << max_num << " ";
	int max_num2 = INT_MIN;
	for (int i = 0; i < N; ++i)
	{
		if (number[i] == max_num)
			continue;
			
		if (number[i] > max_num2)
			max_num2 = number[i];
	}
	cout << max_num2 << endl;
	return 0;
}
