#include <iostream>
using namespace std;
/*
            [Explanation video]
                How many primes - 1

    ● Read 2 integers N and M, then Read matrix NxM.
    ● Then read integer Q, for Q queries.
    ● For each query read 4 integers: i j r c
        ○ Represents a grid (submatrix): top left (i, j) and (r, c) for (# rows, # cols)
    ● For each query, print how many prime numbers in the requested grid.
        ○ Each query should be answered using nested loops maximum not more

    Input ⇒ Output
    ○ 3 4
    ○ 8 2 9 5
    ○ 3 2 27 6
    ○ 7 8 29 22
    ○ 2
    ○ 1 0 2 2 ⇒ 3 (primes 3, 2, 7 in rectangle (0, 1) (2, 1) )
    ○ 0 1 2 3 ⇒ 3 (primes 2, 5, 2 in rectangle (0, 1) (1, 3) )
*/

 // Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    // Check for factors up to sqrt(num)
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    // Read matrix dimensions
    int rows, cols;
    cin >> rows >> cols;

    // Use vector for dynamic allocation and better memory management
    vector<vector<int>> matrix(rows, vector<int>(cols));

    // Read matrix values
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Read number of queries
    int q;
    cin >> q;

    // Process each query
    for (int query = 0; query < q; ++query) {
        int startRow, startCol, numRows, numCols;
        cin >> startRow >> startCol >> numRows >> numCols;

        int primeCount = 0;

        // Count primes in the specified submatrix
        for (int i = startRow; i < startRow + numRows; ++i) {
            for (int j = startCol; j < startCol + numCols; ++j) {
                if (isPrime(matrix[i][j])) {
                    primeCount++;
                }
            }
        }

        cout << primeCount << endl;
    }

    return 0;
}
