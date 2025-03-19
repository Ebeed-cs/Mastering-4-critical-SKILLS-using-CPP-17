#include <iostream>
using namespace std;

                                // Explnation video
/*                                              // approach 1 'using one loop'
                    longest subarray

        Read integer N (< 1000) then N read numbers each is either 0 or 1.
        ● Find the longest subarray with number of zeros = numbers of ones
            ○ You can easily implement it using 3 loops
            ○ Or with little thinking using 2 loops (even with no extra arrays)
            ○ Hard: You can implement it without any nested loops
        ● Inputs ⇒ outputs
            ○ 7 1 0 0 0 1 1 1 ⇒ 6 (e.g. 100011 or 000111)
            ○ 19 1 0 0 0 0 0 1 0 1 1 0 1 0 0 0 0 0 0 1 ⇒ 8 (e.g. 00101101)

*/

int main() {

	int n;
	int a[1000];	// actually 999
	int difference[1000*2+1];	// maximum 2000 values with shift 1000

	// mark the difference as never appeared
	for (int i = 0; i < 2001; ++i)
		difference[i] = 999999;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int maxSubarrayLength1 = 0;
	int maxSubarrayStartIndex1 = -1;
	int maxSubarrayEndIndex1 = -1;

	int added = 0;

	difference[0+1000] = -1;	// difference 0 appears before the array (-1)

	for (int i = 0; i < n; i++)
	{
		if(a[i] == 1)
			added += 1;
		else
			added -= 1;

		int shift = added + 1000;	// shift to make sure positive

		if(difference[shift] == 999999)
			difference[shift] = i;	// first time for such accumulated difference to appear
		else {
			int subarrayLength = i - difference[shift];

			if (subarrayLength > maxSubarrayLength1) {
				maxSubarrayLength1 = subarrayLength;
				maxSubarrayStartIndex1 = difference[shift]+1;
				maxSubarrayEndIndex1 = i;
			}
		}
	}

	if (maxSubarrayLength1 == 0)
		cout << "NOT FOUND" << endl;
	else {
		cout << maxSubarrayLength1 << endl;
		for (int i = maxSubarrayStartIndex1; i <= maxSubarrayEndIndex1; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	// By adding 0 as -1 values, each group of equal ones and zeros
	// is actually sub-array of sum zero


	return 0;
}
