#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void reverse_queue(queue<int>& q) {
    stack<int> s;

    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }

}

int main() {
    queue<int> qu;
    qu.push(2);
    qu.push(15);
    qu.push(4);
    qu.push(7);
    qu.push(13);

    reverse_queue(qu);

    while (!qu.empty()) {
        cout << qu.front() << " ";
        qu.pop();
    }

    return 0;
}


