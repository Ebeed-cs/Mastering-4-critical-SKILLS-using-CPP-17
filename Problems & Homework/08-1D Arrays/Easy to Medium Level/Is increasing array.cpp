#include<iostream>
using namespace std;

/*
				Is increasing array?

	● Read an Integer N, then read N (<= 200) integers. 
	● Print YES if the array is increasing. 
		○ An array is increasing if every element is >= the previous number

	● Inputs  
	○ 4     1 2 2 5   ⇒ YES
	○ 5     1 0 7 8 9  ⇒ NO   [0 is < 1, the previous number]
	○ 2     -10 10 ⇒ YES 
	
	
*/

int main() {
	int N;
	cin >> N;
	int number[N];
	
	for(int i = 0; i< N; ++i)
		cin >> number[i];

	bool increasing = true;
	for(int j = 0; j < N - 1; ++j)
	{
		if(number[j] > number[j + 1])
		{
			increasing = false;
			break;
		}	
	}

	if(increasing)
		cout << "Yes" << endl;
	else	
		cout << "No" << endl;
	return 0;
}
