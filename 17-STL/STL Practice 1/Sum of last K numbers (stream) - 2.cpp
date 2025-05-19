#include <iostream>
#include <queue>
using namespace std;

/*
                    Sum of last K numbers (stream) - 2

            ● This struct will receive stream of numbers, each time return sum of last k numbers
            ● E.g. if k = 4
            ● Stream: 1 2 3 4 5 6 7 8 9
            ● Returns: 1, 1+2, 1+2+3,1+2+3+4, 2+3+4+5, 3+4+5+6, ..
                ○ That is for 6 ⇒ 18
            ● Don’t store more than ~ K numbers

*/

struct last_k_numbers_sum_stream {
	int k;

	int sum = 0;
	queue<int> q;

	last_k_numbers_sum_stream(int _k) {
		k = _k;
	}

	int next(int new_num) {
		// Compute and return sum of last K numbers sent so far
		q.push(new_num);
		sum += new_num;

		if((int)q.size() > k) {
			sum -= q.front();
			q.pop();
		}

		return sum;
	}
};


int main() {
	last_k_numbers_sum_stream processor(4);

	int num;
	while(cin>>num)
		cout<<processor.next(num)<<"\n";

	return 0;
}
