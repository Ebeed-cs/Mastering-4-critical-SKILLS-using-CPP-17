#include<iostream>
using namespace std;

/*
	Guess the output3
*/

int main() {

	int a = 210;

	a /= 2;  		// 105
	cout<<a<<"\n"; // 105 [output]

	cout<<(a /= 3)<<"\n";  // 35	[output]
	cout<<(a /= 5)<<"\n";	// 7	[output]
	cout<<(a /= 7)<<"\n";	// 1	[output]

	cout<<(2+3) * (5-(-3)) / 5 / 8 <<"\n"; // 1 [output]

	a = 10;
	cout<<a++ + 10<<"\n";  // 20 [output]
	cout<<++a + 10<<"\n";  // 22 [output]
	cout<<a-- + 10<<"\n"; //  22 [output]
	cout<<--a + 10<<"\n"; //  20 [output]

	int b = 20;
	cout<<a++ + ++b<<"\n";	// 31 [output]

	cout<<a<<"\n"; // 11 [output]
	++a+=10;	   // 22 
	cout<<a<<"\n";	// 22 [output]



	return 0;
}

