#include<iostream>
using namespace std;


int main() {
	int x;
	cin >> x;

	int count = 0;
	int start, end;

	cin >> start >> end;
	count += (x >= start && x <= end);

	cin >> start >> end;
	count += (x >= start && x <= end);

	cin >> start >> end;
	count += (x >= start && x <= end);

	cout << count << endl;

	return 0;
}

/*
	we used in the approach only two variables to the three intervals
*/
