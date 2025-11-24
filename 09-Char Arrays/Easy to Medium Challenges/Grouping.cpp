#include <iostream>
using namespace std;


int main() {
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if(i && str[i] != str[i - 1]) 
            cout << " ";
        cout << str[i];
    }
    return 0;
}
