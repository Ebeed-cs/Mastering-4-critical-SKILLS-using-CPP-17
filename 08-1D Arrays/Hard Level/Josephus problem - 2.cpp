#include <iostream>
using namespace std;

                            // [Explanation Video]
/*                                  Approcah 2 : using circular linked list using an array 'next'
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
