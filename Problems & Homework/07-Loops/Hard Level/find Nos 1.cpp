#include<iostream>
using namespace std;

/*				
							Approach 1

				Find NOs
	● Read integer N, then read N strings.
		○ Print only the strings (of 2 letters).
		○ These 2 letters must be letter ‘N’ and letter ‘O’
			■ Regardless of lower or upper case
			■ Regardless of the 2 letters order
			■ E.g. print “No”, “ON”, “no”    but ignore e.g. “YEs”, “Noooo”
			■ That is: a word of 2 letters only N and O
	● Input
		○ 9 Yss NO noOO oN Mostafa no nN  oOOooo oO
	● Output
		○ NO oN no


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
