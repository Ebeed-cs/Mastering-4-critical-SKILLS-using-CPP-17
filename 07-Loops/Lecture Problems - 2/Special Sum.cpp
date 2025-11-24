#include<iostream>
using namespace std;


int main() {
	int T;
	cin >> T;
	while (T--)
	{
		int N, num, temp , sum = 0;
		cin >> N;
		for (int i = 1; i <= N; ++i)
		{
			cin >> num;
			temp = 1;
			for(int j = i ; j > 0 ; j--)
				temp *= num;
			sum += temp;
		}
		cout << sum << endl;
	}

	return 0;
}
