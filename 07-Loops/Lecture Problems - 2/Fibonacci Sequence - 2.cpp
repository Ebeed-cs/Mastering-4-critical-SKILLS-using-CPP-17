#include<iostream>
using namespace std;
/*									Approach 2

*/

int main() {
	int N;
	cin >> N;
	for(int a = 0 , b = 1 , c = -1 , i = 0; 
		i < N ;
		 c = a + b , a = b , b = c , ++i )
		cout << a << " ";
	return 0;
}
