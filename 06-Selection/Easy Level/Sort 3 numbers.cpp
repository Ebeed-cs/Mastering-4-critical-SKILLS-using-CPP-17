#include<iostream>
using namespace std;

						// [Explanation video]


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
