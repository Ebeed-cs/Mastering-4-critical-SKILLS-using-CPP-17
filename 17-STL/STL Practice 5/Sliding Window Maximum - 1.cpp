#include <iostream>
#include <vector>
using namespace std;

/*
                Sliding Window Maximum

        Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
            Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
            Output: [3,3,5,5,6,7]
            Explanation:
            Window position                Max
            ---------------               -----
           [1  3  -1] -3  5  3  6  7       3
            1 [3  -1  -3] 5  3  6  7       3
            1  3 [-1  -3  5] 3  6  7       5
            1  3  -1 [-3  5  3] 6  7       5
            1  3  -1  -3 [5  3  6] 7       6
            1  3  -1  -3  5 [3  6  7]      7
*/

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



