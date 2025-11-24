#include<iostream>
using namespace std;

/*					Approach 1 - A
*/

int main() {
	int N;
	cin >> N;
	int number[N];

	for(int i = 0; i < N; ++i) cin >> number[i];

	int count = 0, num = INT_MIN;
	bool increasing = true;
	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
		{
			for (int k = i; k < j + 1; ++k)
			{
				if (num > number[k])
				{
					increasing = false;
					break;
				}
				num = number[k];
			}
			if (increasing)
				count++;
			increasing = true;
			num = INT_MIN;
		}

	cout << count << endl;
	return 0;
}
