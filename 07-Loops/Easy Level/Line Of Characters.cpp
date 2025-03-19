#include<iostream>
using namespace std;

/*

		Line Of Characters
	● Input: Read an integer N followed by a single character
	● Output: Print the character N times as below
	● Input ⇒ Output
		○ 5 Y ⇒ YYYYY
		○ 3 # ⇒ ###

*/

int main() {
	int x;
	char ch;
	cin >> x >> ch;
	while (x > 0)
	{
		cout << ch;
		x--;
	}
	return 0;
}
