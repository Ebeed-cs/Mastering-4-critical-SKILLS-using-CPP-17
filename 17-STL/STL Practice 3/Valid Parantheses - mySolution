#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


int main() {
    unordered_set<char> uns = { ')' , '}' , ']' };
    vector<char> v;
    bool valid = true;

    string input;
    cin >> input;

    for (char val : input) {
        if (uns.count(val)) {
            if ((val == ')' && v.back() == '(') ||
                (val == '}' && v.back() == '{') ||
                (val == ']' && v.back() == '['))
                v.pop_back();
            else {
                valid = false;
                break;
            }
        }
        else
            v.push_back(val);
    }

    if (valid && v.empty())
        cout << "valid paranthesis";
    else
        cout << "invalid paranthesis";

    return 0;
}


