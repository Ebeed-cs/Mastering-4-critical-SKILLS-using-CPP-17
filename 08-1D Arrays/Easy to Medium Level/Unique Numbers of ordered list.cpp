#include<iostream>
using namespace std;

int main() {
	int N , prev , next;
	prev = -1;
	cin >> N;
	for(int i = 0; i< N; ++i)
	{
		cin >> next;
		if(next != prev)
		{
			cout << next << " ";
			prev = next;
		}	
	}
	return 0;
}



