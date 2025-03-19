#include<iostream>
using namespace std;

/*
		 Conditional Count
 ● Write a program that reads number X, then other 5 numbers. Print 2 values:
 	○ How many numbers <= X
 	○ How many numbers > X
 ○ Any relation between these 2 outputs?

 ● Inputs
 ○ 10       300 1 5 100 200
 ○ Output: 2 3
 ○ Explantation
 ○ 2 numbers (1, 5) are <= 10
 ○ 3 numbers (100, 200, 300) are > 10

*/


int main() {
	int x , num1, num2, num3, num4, num5;
	cin >> x >> num1 >> num2 >> num3 >> num4 >> num5;

	int sum = 0;
	sum += (x >= num1);
	sum += (x >= num2);
	sum += (x >= num3);
	sum += (x >= num4);
	sum += (x >= num5);

	cout << sum << " " << 5 - sum << endl;
		return 0;
}

