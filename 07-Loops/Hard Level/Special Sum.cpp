#include<iostream>
using namespace std;


int main() {
	int T;
	cin >> T;
	while (T)
	{
		int N, sum, count, temp;
		sum = count = 0;
		cin >> N;
		while (count < N)
		{
			int num, i;
			cin >> num;
			i = ++count;
			temp = 1;
			while (i > 0)
			{
				temp *= num;
				i--;
			}
			sum += temp;
		}
		cout << sum << endl;
		T--;
	}
	return 0;
}
