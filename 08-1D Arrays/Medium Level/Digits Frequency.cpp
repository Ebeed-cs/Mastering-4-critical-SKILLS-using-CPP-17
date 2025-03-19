#include<iostream>
using namespace std;

/*
		 Digits Frequency

    Description:
    -----------------
    Given an integer N (1 ≤ N ≤ 200), read N numbers.
    For each digit from 0 to 9, count how many times it appears 
    in all the given numbers combined.

    Input:
    -----------------
    - The first line contains an integer N (number of inputs).
    - The next N lines contain N integers.

    Output:
    -----------------
    - Print 10 lines.
    - Each line should contain a digit (from 0 to 9) followed by its count.
    - The output should be sorted from digit 0 to 9.

    Constraints:
    -----------------
    - 1 ≤ N ≤ 200 (maximum 200 numbers to process).
    - Each number can have multiple digits.
    - Numbers are non-negative.

    Example 1:
    -----------------
    Input:
    2
    78 307

    Explanation:
    - The digits in "78" are: 7, 8
    - The digits in "307" are: 3, 0, 7
    - Counting all digits:
        - 0 → 1 time (from 307)
        - 1 → 0 times
        - 2 → 0 times
        - 3 → 1 time (from 307)
        - 4 → 0 times
        - 5 → 0 times
        - 6 → 0 times
        - 7 → 2 times (from 78 and 307)
        - 8 → 1 time (from 78)
        - 9 → 0 times

    Output:
    0 1
    1 0
    2 0
    3 1
    4 0
    5 0
    6 0
    7 2
    8 1
    9 0

*/

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

