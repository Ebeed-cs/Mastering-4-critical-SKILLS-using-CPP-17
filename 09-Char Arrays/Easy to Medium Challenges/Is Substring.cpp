#include <iostream>
using namespace std;


int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO" << endl;
        return 0;
    }

    int i = 0;
    while (input[i] != str[0]) {
        i++;
        if ((int)input.size() <= i) {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int j = 1; j < (int)str.size(); ++j) {
        if (input[++i] != str[j]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
