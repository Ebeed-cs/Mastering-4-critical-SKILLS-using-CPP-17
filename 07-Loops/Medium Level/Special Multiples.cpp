#include<iostream>
using namespace std;


int main() {
	int N, count = 0;
	cin >> N;
	while (count < N)
	{
		if ((count % 8 == 0) || ((count % 4 == 0) && (count % 3 == 0)))
			cout << count << " ";
		count++;
	}
	return 0;
}
