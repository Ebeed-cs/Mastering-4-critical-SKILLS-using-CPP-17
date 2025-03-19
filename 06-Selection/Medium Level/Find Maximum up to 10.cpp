#include<iostream>
using namespace std;

/*
		   Find Maximum up to 10
 ● Read an integer N (2 <= N <= 10)
 ● Then read N integers, find which of them has the biggest value and print it.

 ● Inputs
	○ 5  1 3 2 4 2 ⇒ 4
		■ 5 means read 5 integers
		■ Then we read them [1 3 2 4 2]. Their maximum is 4

	○ 10 1  67  -9  88  -45  129  90  65  77  34 ⇒ 129
		■ Same as last homework. This time we are given first N (10)


*/


int main() {
	int N;
	cin >> N;
	N--;

	int max_num, num;
	cin >> max_num;

	if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }
    if (N > 0) { cin >> num; if (num > max_num) max_num = num; N--; }

	cout << max_num << endl;
	return 0;
}

