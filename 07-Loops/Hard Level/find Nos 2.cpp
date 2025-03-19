#include<iostream>
using namespace std;

/*				
							Approach 2

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

	int pos = 0;

	while (pos < N) {
		string str;
		cin>>str;

		// there are 8 different ways to make 2 letters no in lower/upper cases
		if (str == "no" || str == "No" || str == "nO" || str == "NO" ||
			str == "on" || str == "oN" || str == "On" || str == "ON")
			cout<<str<<" ";

		pos++;
	}
	return 0;
}
