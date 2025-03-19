#include<iostream>
using namespace std;

/*

				Smallest pair

		● Given a number N (<= 200) and an array A of N numbers.
		● Print the smallest possible result of A[i] + A[j] + j - i , where 1  ≤  i < j  ≤  N.

		● Input ⇒ Output
			○ 4   20 1 9 4    ⇒     7

*/

int main() {
	int N;
	cin >> N;
	int number[N];

	for (int i = 0; i < N; ++i) cin >> number[i];

	int min_num = INT_MAX;
	int result;
	for (int i = 0; i < N; ++i)
		for (int j = i + 1; j < N; ++j)
		{
			result = number[i] + number[j] + j - i;
			if (min_num > result)
				min_num = result;
		}
	cout << min_num << endl;
	return 0;
}


/*

Trying to get the 2 min value is wrong, as you need to consider 
i and j locations during minmization

				Ai+Aj+j-i
Test case:
8
10 12 13 14 15 16 17  11

Output: 23

EX : A[0] = 10 , A[7] = 11 'we pick the min two numbers' -> 10 + 11 + 7 - 0 = 28
while the correct answer is : 23
*/

