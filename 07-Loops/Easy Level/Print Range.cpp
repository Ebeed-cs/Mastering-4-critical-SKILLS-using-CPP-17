#include<iostream>
using namespace std;

/*

			Print Range
		● Given a starting number X and an ending number Y, print all numbers between X and Y inclusive, each on a line.
	
		● Input 3 7
		● Output
			○ 3
			○ 4
			○ 5
			○ 6
			○ 7


*/

int main() {
	int x , y;
	cin >> x >> y;
	while(x <= y)
		cout << x++ << endl;
	return 0;
}
