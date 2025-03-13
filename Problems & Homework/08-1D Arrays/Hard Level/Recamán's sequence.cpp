#include<iostream>
using namespace std;

/*
			Recamán's sequence

	● The first terms of this sequence are 0, 1, 3, 6, 2, 7, …
		○ So last term value is 7 and its index is 5 (zero based)
		○ The next value is either:
			■ LastValue - LastIndex - 1 if the following 2 conditions are satisfied:
	● value > 0 and It did not appear before
	● E.g. 7 (last value) - last index (5) - 1 = 7-5-1 = 1   (> 0  but already exists)
			■ Or LastValue + LastIndex + 1 = 7+5+1 = 13

	● Read integer zero-based index ([1, 200]) and print the value of this index
		○ E.g. (6 ⇒ 13) [at index '6' found value '13']
		, (9 ⇒ 21), (17 ⇒ 25)
	● Don’t use nested loops
	● The series is: 0, 1, 3, 6, 2, 7, 13, 20, 12, 21, 11, 22, 10, 23, 9, 24, 8, 25, 43

*/

int main() {
	int N;
	cin >> N;
	const int SIZE = 833;  // the max num can out by the seqeunce up to 200 element is -> 833 
	int freq[SIZE] = { 0 };
	int prev;

	for (int i = 0; i <= N; ++i)
	{
		if (i == 0)
			prev = i;
		else if (((prev - i) > 0) && (!freq[prev - i]))
			prev = prev - i;
		else
			prev = prev + i;

		freq[prev]++;
	}

	cout << prev << " ";
	return 0;
}
