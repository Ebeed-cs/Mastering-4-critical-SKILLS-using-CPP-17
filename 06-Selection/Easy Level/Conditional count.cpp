#include<iostream>
using namespace std;



int main() {
	int x , num1, num2, num3, num4, num5;
	cin >> x >> num1 >> num2 >> num3 >> num4 >> num5;

	int sum = 0;
	sum += (x >= num1);
	sum += (x >= num2);
	sum += (x >= num3);
	sum += (x >= num4);
	sum += (x >= num5);

	cout << sum << " " << 5 - sum << endl;
		return 0;
}

