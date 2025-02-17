#include<iostream>
using namespace std;

/*				Approcah 1
			 Find first and 2nd Maximum values

	● Read an Integer N ( < 200), then read N (distinct) integers. Find the maximum and 2nd maximum values

	● Input: 5  10 20 3 30 7 ⇒ Output 30 20
		○ 30 is the maximum in the array
		○ If we removed it, the next maximum is 20

*/

int main() {
	int N, max_num = INT_MIN;
	cin >> N;
	int number[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> number[i];
		if (number[i] > max_num)
			max_num = number[i];
	}
	cout << max_num << " ";
	int max_num2 = INT_MIN;
	for (int i = 0; i < N; ++i)
	{
		if (number[i] == max_num)
			continue;
			
		if (number[i] > max_num2)
			max_num2 = number[i];
	}
	cout << max_num2 << endl;
	return 0;
}
