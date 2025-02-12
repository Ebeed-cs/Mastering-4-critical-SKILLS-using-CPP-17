#include<iostream>
using namespace std;

/*
				Special Average
	● Read integer N, followed by reading N numbers. Print 2 values
		○ The average of the numbers in odd positions (1st, 3rd, 5th, …)
		○ The average of the numbers in even positions (2nd, 4th, 6th, …)

	● Input
		○ 6 10 100 20 200 30 600
	● Output
		○ 20  300
	● Explantation
		○ (10+20+30)/3 = 20
		○ (100+200+600)/3 = 300

*/

int main() {
	int N, input , count;
	double even_num, odd_num; // 'double' if the average is a floating number
	count = even_num = odd_num = 0;
	cin >> N;

	while (N != count)
	{
		++count;
		cin >> input;
		if (count % 2 == 0)
			even_num += input;
		else
			odd_num += input;
	}

		// count of odd numbers
	if(N % 2 != 0)
		N = N/2 + 1;  
	else	
		N = N/2;
		
	cout << odd_num / N << " " << even_num  / (count / 2) << endl;
	return 0;
}

/*
		if N = 5 -> odd : 3 , even : 2
		if N = 6 -> odd : 3 , even : 3
		then number of odd numbers -> if N (even) : N / 2, if N (odd) : N/2 + 1
		then number of even numbers ->if N (even) : N / 2, if N (odd) : N/2

	Test case (double)
 * Input: 7 11 101 21 201 31 602 78
 *
 * Output: 35.25 301.333
*/
