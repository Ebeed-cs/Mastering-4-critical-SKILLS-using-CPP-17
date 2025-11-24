#include <iostream>
#include <stack>
using namespace std;


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
