#include<iostream>
using namespace std;


int main() {
	int T , N , input , min_num;
	cin >>T;
	while(T--)
	{
		min_num = INT_MAX;
		cin >> N;

		while(N > 0)
		{
			cin >> input;
			if(input < min_num)
				min_num = input;
			N --;
		}

		cout << min_num << endl;
	}
	return 0;
}

