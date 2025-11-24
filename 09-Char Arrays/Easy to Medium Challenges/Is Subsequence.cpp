#include <iostream>
using namespace std;

int main() {
    string input, str;
    cin >> input >> str;

    if (str.size() > input.size()) {
        cout << "NO" << endl;
        return 0;
    }

    int count , str_size;
    str_size = count = 0;

    while(count < input.size())
        if(input[count ++] == str[str_size]) str_size++;
    
    if(str_size != str.size() - 1)
        cout << "Yes" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
