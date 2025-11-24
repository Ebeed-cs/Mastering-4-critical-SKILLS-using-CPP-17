#include<iostream>
using namespace std;



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
