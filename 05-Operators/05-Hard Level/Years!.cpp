
#include<iostream>
using namespace std;

/*

	Years!

Assume a year is 12 months, but each month is 30 days

That is a year has 12 * 30 = 360 days
Read an integer: whole number of days of someone's age. Print 3 numbers   

Total years total months remaining days
Inputs => Outputs

360 => 1 0 0 		each 360 days a year
30 => 0 1 0 		each 30 days a month
10 => 0 0 10 		just days infant!
391 => 1 1 1 		391 = 360 + 30 + 1 = 1 year, 1 month, 1 day   
61 => 0 2 1 		61 = 2*30 + 1
200 => 0 6 20 		200 = 6*30 + 20   
1000 => 2 9 10 		1000 = 2360 + 930 + 10
5000 => 13 10 20

*/

int main() {
	int num;
	cin >> num;
	int year = num / 360; // to can get the number of comblete years iterations
	num %= 360;			  // to remove the year iterations to can deal with monthes and days

	int month = num / 30; // to get the number of comblete monthes iterations
	num %= 30;			  // to reomve the monthes iterations 

	int day = num;		  // the remaining is number of days

	cout << year << " " << month <<  " " << day << endl;

	return 0;
}
