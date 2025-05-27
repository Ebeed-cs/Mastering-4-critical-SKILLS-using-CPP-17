#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
                           Next Greater Element - 2

                           https://leetcode.com/problems/daily-temperatures/description/

        ● Given an array, for every number, find the first number after it of a higher value
        ● E.g. 10, 5, 7, 15, 11 ⇒ 15 7 15 -1 -1
            ○ First number greater than 10 ⇒ 15
            ○ First number greater than 5 ⇒ 7
            ○ First number greater than 7 ⇒ 15
            ○ First number greater than 15 and 11 ⇒ None, so use -1
        ● Input:
            ○ 8 ,73, 74, 75, 71, 69, 72, 76, 73 ⇒ 73 74 75 76 72 72 76 -1 -1
        ● We can easily solve that with 2 nested loops
        ● We can solve it with 1 loop using stack. Find it

        // https://www.geeksforgeeks.org/next-greater-element/

*/

vector<int> next_greater_num(vector<int>& v) {
	vector<int> result(v.size(), -1);
	stack<int> pos;

	for (int i = 0; i < (int) v.size(); ++i) {
		while (!pos.empty() && v[i] > v[pos.top()])
			result[pos.top()] = v[i], pos.pop();
		pos.push(i);
	}
	return result;
}

int main() {
	vector<int> v = { 73, 74, 75, 71, 69, 72, 76, 73 };
	v = next_greater_num(v);

	for (auto x : v)
		cout << x << " ";
	return 0;
}
