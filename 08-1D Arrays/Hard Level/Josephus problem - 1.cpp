#include <iostream>
using namespace std;

/*                                  Approcah 1 : using frequency array to mark the eliminated person
*/

int main() {
    int N, K;
    cin >> N >> K;
    int feq_arr[N + 1] = { 0 };
    int i = 1, stop = N, index;
    while(stop){
        int count = K;
        while(count ){
            index = i % N;
            if(! index) index = N;
            i++;
            if(! feq_arr[index])count --;
        }
        feq_arr[index] ++;
        cout << index << " ";
        stop --;
    }
    return 0;
}

