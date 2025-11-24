#include <iostream>
#include <queue>
using namespace std;


void sum_qu(queue<int> qu) {
    int sum = 0;
    while (!qu.empty()) {
        sum += qu.front();
        qu.pop();
    }
    cout << sum << endl;
}

int main() {
    int k, input;
    queue<int> qu;
    cin >> k;
    while (qu.size() != k) {
        cin >> input;
        qu.push(input);
        sum_qu(qu);
    }
    while (true) {
        cin >> input;
        qu.pop();
        qu.push(input);
        sum_qu(qu);
    }
    return 0;
}
