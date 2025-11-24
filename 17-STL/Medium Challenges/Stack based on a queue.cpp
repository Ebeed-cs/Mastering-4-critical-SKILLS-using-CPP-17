#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct OurStack {
    queue<int> q;

    void push(int val) {
        q.push(val);
        int size = q.size();
        while (--size > 0) {
            q.push(q.front()) , q.pop();
        }
    }

    void pop() {
        if (!q.empty())
            q.pop();
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};

int main() {

    OurStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    while (!s.empty())
        cout << s.top() << " ", s.pop();

    return 0;
}


