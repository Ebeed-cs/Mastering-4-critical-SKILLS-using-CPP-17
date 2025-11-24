#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {8, 7, 6, 9, 3, 2, 1, 10};
    vector<int>::iterator it = v.begin();
    int k, max = *it;
    cin >> k;
    for(; it < v.begin() + k; ++it){
        if(max < *it)
            max = *it;
    }
    cout << max << " ";
    while(it != v.end()){
        if(*(it - k ) >= max){
            it -=(k - 1);
            max = *it;
            for(auto it2 = it; it2 < it + k; it2++)
                if(max < *it2)
                    max = *it2;
            it += k;
        }
        else{
            if(max < *it)
                max = *it;
            it ++;
        }
        cout << max << " ";
    }

    return 0;
}



