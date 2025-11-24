#include<iostream>
using namespace std;


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

