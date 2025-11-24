#include<iostream>
using namespace std;

/*					
					Approach 2
*/

int main() {
	int N;
	cin >> N;
	int number[N];

	for(int i = 0; i < N; ++i) cin >> number[i];

	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		count ++;    // single element is always valid
		for (int j = i + 1; j < N ; ++j)
		{
			if(number[j] <= number[j - 1])	
				break;
			count ++;
		}
	}

	cout << count << endl;
	return 0;
}

/*
i = 0:
  j = 0: [1] valid ✓
  j = 1: [1,2] check if 2>1 ✓
  j = 2: [1,2,3] check if 3>2 ✓
  j = 3: [1,2,3,4] check if 4>3 ✓

i = 1:
  j = 1: [2] valid ✓
  j = 2: [2,3] check if 3>2 ✓
  j = 3: [2,3,4] check if 4>3 ✓
...
*/
