#include<iostream>
using namespace std;

/*
						Approcah 2
			 Find first and 2nd Maximum values

	● Read an Integer N ( < 200), then read N (distinct) integers. Find the maximum and 2nd maximum values

	● Input: 5  10 20 3 30 7 ⇒ Output 30 20
		○ 30 is the maximum in the array
		○ If we removed it, the next maximum is 20

*/

int main() {
	int N;
	cin >> N;
	int number[N];
	for (int i = 0; i < N; ++i)
		cin >> number[i];

	int max1, max2; // max1 will has first max value and max2 the 2nd max
	if (number[0] >= number[1])
		max1 = number[0], max2 = number[1];
	else
		max1 = number[1], max2 = number[0];

	for (int i = 2; i < N; ++i)
	{
		if (number[i] > max1)
			max2 = max1, max1 = number[i];
		else if (max2 < number[i])
			max2 = number[i];
	}

	cout << max1 << " " << max2;
	return 0;
}
