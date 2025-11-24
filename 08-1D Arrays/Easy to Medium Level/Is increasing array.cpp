#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int number[N];
	
	for(int i = 0; i< N; ++i)
		cin >> number[i];

	bool increasing = true;
	for(int j = 0; j < N - 1; ++j)
	{
		if(number[j] > number[j + 1])
		{
			increasing = false;
			break;
		}	
	}

	if(increasing)
		cout << "Yes" << endl;
	else	
		cout << "No" << endl;
	return 0;
}
