#include<iostream>
using namespace std;

							// Approach 2
/*
		 Maximum but constrained 
	● Given 3 integers, you have to find the biggest one of them which is < 100. 
	○ Print -1 if no such number

 ● Inputs
 ○ 22 90 115 ⇒ 90
 	■ Here [20 90] are only < 100. Maximum (20, 90) = 90
 ○ 200 300 400 ⇒ -1
 	■ All of them are > 100, so no answer
 ○ 50 100 150 ⇒ 50
 	■ Only 50 is < 100.
 ○ 10 30 20 ⇒ 30
 	■ The 3 numbers < 100, so their max is 30

*/

		
int main() {
	int num1, num2, num3;
	cin >> num1 >> num2 >> num3;
	int result = -1; // put with '-1' beacouse if all the numbers are > 100 then will output the value of 'result' which is -1
		
		// initialize the result variable , we will check on the three numbers beacouse if only one of them is < 100 if all > 100 then will remain -1 which will be the output
	if(num1 < 100)
		result = num1;
	if(num2 < 100)
		result = num2;
	if(num3 < 100)
		result = num3;

		// get the correct max number and < 100
	if(num1 < 100 && num1 > result)
		result = num1;
	if(num2 < 100 && num2 > result)
		result = num2;
	if(num3 < 100 && num3 > result)
		result = num3;
	cout << result << endl;
		return 0;
}
