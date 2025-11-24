#include <iostream>
using namespace std;


int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO" << endl;
        return 0;
    }

    int size_str = str.size();
    int size_input = input.size();

    while(size_str){
        if(input[--size_input] != str[--size_str]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
