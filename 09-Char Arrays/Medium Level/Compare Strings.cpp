#include <iostream>
using namespace std;


int main() {
    string str1 , str2;
    cin >> str1 >> str2;

    int len = str1.size();
    if(len > str2.size())
        len = str2.size();

    int i = 0;
    while(len && str1[i] == str2[i]) i++ , len--;

    if(!len){
        if(str1.size() <= str2.size()) cout << "YES";
        else cout << "NO";
    }
    else{
        int count1 = (int)str1[i];
        int count2 = (int)str2[i];

        while(count1 && count2)
            count1-- , count2 --;
        
        if(!count1) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
