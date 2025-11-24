#include<iostream>
using namespace std;


int main() {
	int A , B;
	cin >> A >> B;
	bool A_even = (A % 2 == 0);
	bool B_even = (B % 2 == 0);
	if(!A_even && !B_even)
		cout << A * B << endl;
	else if(A_even && B_even)
		cout << A / B << endl;
	else if(!A_even && B_even)
		cout << A + B << endl;
	else
		cout << A - B << endl;
	return 0;
}
