#include <iostream>
using namespace std;
/*
            Is Palindrome Array
    ● Read N, then N integers for an Array. Call a function with the array to check if the array is palindrome or note
        ○ We already coded it before
        ○ Just copy code and rearrange to call function with array

*/
void is_palidrome(int N) {
    int number[100];
    for (int i = 0; i < N / 2; ++i)
        cin >> number[i];

    int input;

    if (N % 2 != 0)
        cin >> input; // regardless the middle number

    for (int j = N / 2 - 1; j >= 0; --j)
    {
        cin >> input;
        if (number[j] != input)
        {
            cout << "No" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int main() {
    int N;
    cin >> N;
    is_palidrome(N);
    return 0;
}
