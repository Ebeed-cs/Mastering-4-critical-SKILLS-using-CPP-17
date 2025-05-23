#include <iostream>
#include <stack>
using namespace std;

/*
                    Remove All Adjacent Duplicates In String

            https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
                    
            Given a string s of lowercase letters, a duplicate removal consists of choosing two
            adjacent and equal letters, and removing them.

            We repeatedly make duplicate removals on S until we no longer can.

            Return the final string after all such duplicate removals have been made. It is
            guaranteed the answer is unique.

            Use a stack
            · string
            · removeDuplicates(string S)

            Example 1:

            Input: "abbaca"
            Output: "ca"
            Explanation:
            For example, in "abbaca" we could remove "bb" since the letters
            are adjacent and equal, and this is the only possible move. The
            result of this move is that the string is "aaca", of which only
            "aa" is possible, so the final string is "ca".

*/

string removeDuplicates(string S) {
    stack<char> st;
    for (char ch : S) {
        if (!st.empty() && st.top() == ch)
            st.pop();
        else
            st.push(ch);
    }
    string ret = "";
    while (!st.empty()) {
        ret += st.top();
        st.pop();
    }
    return ret;
}

int main() {
    cout << removeDuplicates("abbaca") << endl; // ac
    cout << removeDuplicates("webbew") << endl; // ""
    cout << removeDuplicates("ahmmhea") << endl;// aea
    return 0;
}
