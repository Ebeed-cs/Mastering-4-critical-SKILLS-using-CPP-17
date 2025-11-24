#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	const int SIZE = 500 + 1;
	int freq[SIZE] = { 0 };
	int input;

	for(int i = 0; i < N; ++i)
	{
		cin >> input;
		if(! freq[input])
		{
			cout << input << " ";
			freq[input] = 1;
		}
	}

	return 0;
}

