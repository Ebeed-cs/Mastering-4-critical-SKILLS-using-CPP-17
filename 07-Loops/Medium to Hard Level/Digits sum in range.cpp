#include<iostream>
#include <cmath>
using namespace std;


int main() {
	int N, A, B, result = 0;
	cin >> N >> A >> B;
	for (int i = 1; i <= N; ++i)
	{
		int sum = 0;
		int num = i;
		while (num > 0)
		{
			sum += num % 10;
			num /= 10;
		}
		if (sum >= A && sum <= B)
			result += i;
		sum = 0;
	}
	cout << result << endl;

	return 0;
}

