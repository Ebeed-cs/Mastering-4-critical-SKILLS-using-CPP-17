#include <iostream>
#include <stack>
using namespace std;


int scoreOfParentheses(string str) {
    stack<int> st;
    st.push(0);
    for (char ch : str) {
        if (ch == '(')
            st.push(0);
        else {
            int last = st.top();
            st.pop();
            if (last == 0)
                last = 1;
            else
                last *= 2;

            int parent_par = last + st.top();
            st.pop();
            st.push(parent_par);
        }
    }
    return st.top();
}

int main() {
    cout << scoreOfParentheses("(()(()))(()(()))") << endl;	// 12
    cout << scoreOfParentheses("()") << endl; // 1
    cout << scoreOfParentheses("(())") << endl; // 2
    cout << scoreOfParentheses("()()") << endl; // 2 
    cout << scoreOfParentheses("(()())") << endl; // 4
    cout << scoreOfParentheses("(()(()))") << endl; // 6
    cout << scoreOfParentheses("()((())())") << endl; // 7
    return 0;
}
