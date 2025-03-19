#include <iostream>
using namespace std;

                            // [Explanation Video]
/*                                  Approcah 2 : using circular linked list using an array 'next'
                Josephus problem 

    ● Read integers N (< 200) and K (<= 1000000). Code for small K first
        ○ Find the game winner for following game:
    ● There is a group of N people in Circle numbered 1, 2, …. N
        ○ Someone is a master of the game.
        ○ He starts from Person #1. Count K. Then remove this person from the circle.
        ○ He keeps doing so till only 1 person remains. This is the winner.

    ● Input 4 2
        ○ Means we have people: 1, 2, 3, 4. Master starts at 1
        ○ Count 2 persons (2 removed), start from 3
        ○ Count 2 persons (4 removed), start from 1
        ○ Count 2 persons (3 removed), 1 is winner
    ● Output
        ○ People removed in order: 2 4 3 1

    Input ⇒ Output
        ○ 7 1 ⇒ 1 2 3 4 5 6 7
        ○ 7 2 ⇒ 2 4 6 1 5 3 7
        ○ 7 3 ⇒ 3 6 2 7 5 1 4
        ○ 7 4 ⇒ 4 1 6 5 7 3 2
        ○ 7 5 ⇒ 5 3 2 4 7 1 6
        ○ 7 6 ⇒ 6 5 7 2 1 4 3
        ○ 7 7 ⇒ 7 1 3 6 2 4 5
        ○ 7 14 ⇒ 7 2 6 3 5 4 1
        ○ 7 1000 ⇒ 6 3 2 1 4 7 5
        ○ 7 99999 ⇒ 4 7 5 2 1 3 6

*/

int main() {
    int N, K;
    cin >> N >> K;
    
    // Create a circular linked list representation using an array
    int next[201]; // Array to represent "next person" for each position
    
    // Initialize the circular list: 1->2->3->...->N->1
    for (int i = 1; i <= N; i++) {
        next[i] = (i % N) + 1;
    }
    
    int current = 1; // Start from person 1
    int prev = N;    // Person N points to person 1
    
    // Eliminate N people one by one
    for (int i = 0; i < N; i++) {
        // Find the Kth person
        for (int j = 0; j < K - 1; j++) {
            prev = current;
            current = next[current];
        }
        
        // Output the eliminated person
        cout << current << " ";
        
        // Remove the current person from the circle
        next[prev] = next[current];
        
        // Move to the next person in the circle
        current = next[current];
    }
    
    return 0;
}
