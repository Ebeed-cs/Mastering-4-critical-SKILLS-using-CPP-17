#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	int freq[502] = { 0 };
	int input;

	for (int i = 0; i < N; ++i)
	{
		cin >> input;
		freq[input + 1] = i + 1;
	}

	int Q;
	cin >> Q;
	while (Q--)
	{
		cin >> input;
		if (freq[input + 1] > 0)
			cout << freq[input + 1] - 1 << endl;
		else
			cout << -1 << endl;
	}
	return 0;
}
