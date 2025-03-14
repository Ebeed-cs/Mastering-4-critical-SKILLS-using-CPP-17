#include <iostream>
using namespace std;

/*
                       Compare strings

    ● Read 2 strings, then output YES if the first smaller than or equal to second.
                            Otherwise, output NO

        ○ Don’t use < operator to compare strings. Use loops

    ● Input ⇒ Output
        ○ aaa aaa ⇒ YES
        ○ aaaaa aa ⇒ NO
        ○ abc d ⇒ YES
        ○ dddddddddddddd xyz ⇒ YES
        ○ azzzzzzzz za ⇒ YES
        ○ za azzzzzzzz ⇒ NO

*/

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
