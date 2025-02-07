#include<iostream>
using namespace std;

/*

	100 or 7?
 ● Write a program that reads an integer and print 100 if number is even or 7 if number is odd
 ○ E.g. for input 8 ⇒ 100
 ○ E.g. for input 133 ⇒ 7


*/

int main() {
	int num;
	cin >> num;
	int result = (num % 2 == 0) * 100 + !(num % 2 == 0) * 7;
	cout << result << endl;
	return 0;
}

/*
	we also can make instead of : !(num % 2 == 0) -> 1 - (num % 2 == 0)
*/
