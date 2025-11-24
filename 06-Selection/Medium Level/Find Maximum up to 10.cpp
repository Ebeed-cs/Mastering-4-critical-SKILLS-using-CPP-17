#include<iostream>
using namespace std;



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

