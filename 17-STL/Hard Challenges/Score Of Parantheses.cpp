#include <iostream>
#include <stack>
using namespace std;

/*
                            Score of Parentheses
[Explnation linK: https://youtu.be/d79Bro_DXOM]

                    https://leetcode.com/problems/score-of-parentheses/

                    Given a balanced parentheses string s, compute the score of the string based on the
                    following rule:

                        · () has score 1
                        . AB has score A + B, where A and B are balanced parentheses strings.
                        · (A) has score 2 * A, where A is a balanced parentheses string.

                    · Use stack
                    · Inputs
                        ()=1
                        (())=2
                        ()()=2
                        (()())=4
                        (()(()))=6
                        ()((())())=7

*/

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
