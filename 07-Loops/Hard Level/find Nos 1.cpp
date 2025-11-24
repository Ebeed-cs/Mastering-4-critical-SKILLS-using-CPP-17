#include<iostream>
using namespace std;

/*				
							Approach 1

*/

int main() {
	int N;
	cin >> N;
	string input;
	while (N > 0)
	{
		cin >> input;
		if (input.length() == 2)
		{
			if (((input[0] == 'N' || input[0] == 'n') &&
				(input[1] == 'O' || input[1] == 'o')) || ((input[1] == 'N' || input[1] == 'n') &&
					(input[0] == 'O' || input[0] == 'o')))
				cout << input << " ";
		}

		N--;
	}
	return 0;
}

/*
	if input[0] -> (N or n) and input[1] -> (O or o)
	if input[1] -> (O or o) and input[1] -> (N or n)
*/
