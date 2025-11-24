#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int freq[10] = { 0 };
	int input;

	while(N--)
	{
		cin >> input;

		if(input == 0)    // be aware 
			freq[0]++;
		
		while(input > 0)
		{
			freq[input % 10] ++;
			input /= 10;
		}
	}

	for(int i = 0; i< 10; ++i)
		cout << i << " " << freq[i] << endl;
	return 0;
}

