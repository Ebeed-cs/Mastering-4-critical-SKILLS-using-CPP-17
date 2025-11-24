#include<iostream>
using namespace std;


int main() {
	int num;
	cin >> num;
	int result = (num % 2 == 0) * 100 + !(num % 2 == 0) * 7;
	cout << result << endl;
	return 0;
}

/*
	we also can make instead of : !(num % 2 == 0) -> 1 - (num % 2 == 0)
*/
