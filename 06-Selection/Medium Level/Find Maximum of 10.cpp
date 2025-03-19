#include<iostream>
using namespace std;

/*
		  Find Maximum of 10
 ● Read 10 integers, find which of them has the biggest value and print it.
 ● Inputs
 ○ 1  67  -9  88  -45  129  90  65  77  34 ⇒ 129
 ● Restriction: In your whole code there should be 2 integer variables defined 
	ONLY
 ○ If it is hard constraint; code it in whatever way


*/


int main() {
	int num, max_num;

    // Read the first number and initialize max_num
    cin >> max_num;  

    // Read and compare the next 9 numbers manually
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;
    cin >> num; if (num > max_num) max_num = num;

    // Print the maximum number
    cout << max_num << endl;
    return 0;
}

