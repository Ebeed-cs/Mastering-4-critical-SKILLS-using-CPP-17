#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int number[N];
	int reapeated_num[150] = {0};
	
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		reapeated_num[number[i] - 1]++;
	}

	int max_repeated_index = 0;

	for (int j = 0; j < 150; ++j)
		if (reapeated_num[max_repeated_index] < reapeated_num[j])
			max_repeated_index = j;
			
	cout << max_repeated_index + 1 << " repeated " << reapeated_num[max_repeated_index] << " times" << endl;
	return 0;
}

/*
We used a trick called frequency array
*/
