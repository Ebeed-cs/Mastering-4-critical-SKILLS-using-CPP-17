#include<iostream>
using namespace std;

							// Approach 1
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
	if (num1 > num2)
	{
		num1 = num1 + num2;
		num2 = num1 - num2;
		num1 = num1 - num2;
	}
	if (num2 > num3)
	{
		num2 = num2 + num3;
		num3 = num2 - num3;
		num2 = num2 - num3;
	}
	if (num1 > num2)
	{
		num1 = num1 + num2;
		num2 = num1 - num2;
		num1 = num1 - num2;
	}

	if(num3 < 100)
		cout << num3 << endl;
	else if(num2 < 100)
		cout << num2 << endl;
	else if(num1 < 100)
		cout << num1 << endl;
	else 
		cout << -1 << endl;
		return 0;
}

/*
	here we sort it like we did in problem 'sort three numbers' and then check if the biggest number is less than 100 then will be the output if not go to the less than one and so on , if all three numbers are bigger than 100 then we wil out -1 in the else part
*/
