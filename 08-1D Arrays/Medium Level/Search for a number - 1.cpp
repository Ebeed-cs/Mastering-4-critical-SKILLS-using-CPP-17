#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int number[N];

	for (int i = 0; i < N; ++i) cin >> number[i];

	int Q, input;
	cin >> Q;
	while (Q--)
	{
		cin >> input;
		int pos = -1;
		
		for (int i = N - 1; i >= 0; --i)
		{
			if (input == number[i])
			{
				pos = i;
				break;
			}	
		}
		cout << pos << " ";
	}

	return 0;
}
