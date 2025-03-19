#include<iostream>
using namespace std;

						// [Explanation video]
/*
	 Sort 3 numbers
 ● Given 3 integers, sort (order) them in ascending order and print them .

 ● Inputs ⇒ outputs
 ○ 1 2 3 ⇒ 1 2 3
 ○ 1 3 2 ⇒ 1 2 3
 ○ 2 1 3 ⇒ 1 2 3
 ○ 2 3 1 ⇒ 1 2 3
 ○ 3 1 2 ⇒ 1 2 3
 ○ 3 2 1 ⇒ 1 2 3
 ● Do you notice there are only 6 ways to permutate 3 numbers!


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
	cout << num1 << " " << num2 << " " << num3;
	return 0;
}

// here we did swap using two variables