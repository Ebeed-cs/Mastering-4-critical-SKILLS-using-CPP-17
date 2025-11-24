#include<iostream>
using namespace std;


int main() {
	int N;
	cin >> N;
	int freq[270 + 500 + 1] = { 0 }; // shift to each element by 500 to advance , and 1 element to be in safe
	int input;

	for (int i = 0; i < N; ++i)
		cin >> input,freq[input + 500]++;

	int max_index = 0;
	for(int i = 1; i < 770; ++i)
		if(freq[max_index] < freq[i])
			max_index = i;

	cout << max_index - 500 << " repeated " << freq[max_index] << " times";  		
	return 0;
}

