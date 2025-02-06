#include<iostream>
using namespace std;

/*
	 Our remainder
 ● We know N % M computes the remainder of division
 ● Write a program that reads 2 positive integers and print such reminder without using the modulus operator %
 ● Input: 27 12
 ● Output: 3
 ○ Remember in math: 27 % 12 = 3



*/
int main() {
	int num1, num2;
	cin >> num1 >> num2;
	int solid_part = num1 / num2;
	int result = num1 - solid_part * num2;
	cout << result << endl;
	return 0;
}

/*
	 let's try 13/5
	 13/5 = 2  [2 complete units, each is 5]
	 2*5 = 10  [total complete units]
	 Reminder is 13-10 = 3. This number generates the fractional part
*/
