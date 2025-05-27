#include <iostream>
#include <vector>
using namespace std;

/*
                           Next Greater Element - 1

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


*/

vector<int> next_greater(vector<int>& v) {
    vector<int> result;
    for (auto it = v.begin(); it < v.end(); ++it) {
        auto it2 = it + 1;
        for (; it2 < v.end(); ++it2)
            if (*it2 > *it)
                break;
        if (it2 != v.end())
            result.push_back(*it2);
        else
            result.push_back(-1);
    }
    return result;
}

int main() {
    vector<int> v = { 10, 5, 7, 15, 11 };

    v = next_greater(v);

    for (int val : v)
        cout << val << " ";
    return 0;
}
