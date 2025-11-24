
#include<iostream>
using namespace std;


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
