#include<iostream>
using namespace std;

/*
		 	Unique Numbers of unordered list 

	● Read integer N ( <= 900), followed by reading N integers (0 <= value <= 500)
	● Print the unique list of the numbers, but preserve the given order
	
	● Input:    13       
		1 5 5 2 5 7 2 3 3 3 5 2 7
 	● Output: 1 5 2 7 3
		○ Observe: input is not sorted list
		○ Observe: output preserves the original order: e.g. 5 appears before 2
 	● Don’t use nested loops


*/

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

