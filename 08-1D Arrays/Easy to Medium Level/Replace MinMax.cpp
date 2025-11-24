#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int number[N];

	int min_num = 2000;
	int max_num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		if (number[i] > max_num)
			max_num = number[i];
		if (number[i] < min_num)
			min_num = number[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (number[i] == min_num)
			number[i] = max_num;

		else if (number[i] == max_num)
			number[i] = min_num;
	}

	for (int i = 0; i < N; ++i)
	{
		if(i)
			cout <<" ";
		
		cout << number[i];
	}
	return 0;
}
