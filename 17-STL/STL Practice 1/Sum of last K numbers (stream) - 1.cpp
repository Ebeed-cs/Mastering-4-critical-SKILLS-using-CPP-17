#include <iostream>
#include <queue>
using namespace std;

/*
                    Sum of last K numbers (stream) - 1

            ● This struct will receive stream of numbers, each time return sum of last k numbers
            ● E.g. if k = 4
            ● Stream: 1 2 3 4 5 6 7 8 9
            ● Returns: 1, 1+2, 1+2+3,1+2+3+4, 2+3+4+5, 3+4+5+6, ..
                ○ That is for 6 ⇒ 18
            ● Don’t store more than ~ K numbers

*/

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
