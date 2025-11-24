#include<iostream>
using namespace std;


int main() {
	int N, M, count;
	cin >> N >> M;
	int left = 0;
	while (N > 0)
	{
		count = 1;
		left++;
		while (count <= M)
		{
			cout << left << " x " << count << " = " << left * count << endl;
			count++;
		}
		N--;
	}
	return 0;
}
