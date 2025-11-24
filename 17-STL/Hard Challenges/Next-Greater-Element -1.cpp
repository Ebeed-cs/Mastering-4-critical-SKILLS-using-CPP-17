#include <iostream>
#include <vector>
using namespace std;


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
