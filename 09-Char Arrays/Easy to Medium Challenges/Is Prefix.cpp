#include <iostream>
using namespace std;


int main() {
    string input , str;
    cin >> input >> str;

    if(str.size() > input.size()){
        cout << "NO" << endl;
        return 0;
    }

    for(int i = 0; i < (int) str.size(); ++i){
        if(input[i] != str[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
