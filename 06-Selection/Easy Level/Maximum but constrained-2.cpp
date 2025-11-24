#include<iostream>
using namespace std;

							// Approach 2

		
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
