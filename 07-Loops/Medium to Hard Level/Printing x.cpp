#include<iostream>
using namespace std;
/*
			Printing X

		● Read an Integer N, then print an X using * as following
			○ N always odd
				5
				*   *
				 * *
                  *
 			     * *
				*   *

*/

int main() {
	int n;

	cin>>n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if(i == j || n-i-1 == j)
				cout<<"*";
			else
				cout<<" ";
		}
		cout<<"\n";
	}

	return 0;
}
