#include <iostream>
using namespace std;
/*
            NxN tic-tac-toe - 2

    Read integer N for the dimension of tic-tac-toe (3 <= N <= 9). Then run a game of 2 users who keep playing till one of them wins or tie. Print the grid
after each round. Checkout below
*/
int main() {
    int N;
    cout << "Enter the dimension N (3 <= N <= 9): ";
    cin >> N;

    // Initialize the grid
    char grid[9][9] = {};

    // Fill the grid with empty spaces
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            grid[i][j] = ' ';
        }
    }

    // Variables to keep track of the game state
    bool game_over = false;
    char current_player = 'X';
    int moves = 0;

    // Game loop
    while (!game_over) {
        // Print the grid
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << grid[i][j];
                if (j < N - 1) cout << "|";
            }
            cout << endl;
            if (i < N - 1) {
                for (int j = 0; j < 2 * N - 1; ++j) cout << "-";
                cout << endl;
            }
        }

        // Get the current player's move
        int row, col;
        cout << "Player " << current_player << ", enter your move (row col): ";
        cin >> row >> col;

        // Adjust for 0-based indexing
        row--;
        col--;

        // Check if the move is valid
        if (row >= 0 && row < N && col >= 0 && col < N && grid[row][col] == ' ') {
            grid[row][col] = current_player;
            moves++;

            // Check for a win
            bool win = false;

            // Check row
            bool row_win = true;
            for (int j = 0; j < N; ++j) {
                if (grid[row][j] != current_player) { // i need to check the row only which i now work in it not all the rows every time because the updated only which i add at
                    row_win = false;
                    break;
                }
            }
            if (row_win) win = true;

            // Check column
            bool col_win = true;
            for (int i = 0; i < N; ++i) {
                if (grid[i][col] != current_player) {
                    col_win = false;
                    break;
                }
            }
            if (col_win) win = true;

            // Check diagonals
            bool diag1_win = true;
            bool diag2_win = true;
            for (int i = 0; i < N; ++i) {
                if (grid[i][i] != current_player) diag1_win = false;
                if (grid[i][N - 1 - i] != current_player) diag2_win = false;
            }
            if (diag1_win || diag2_win) win = true;

            // If win, end the game
            if (win) {
                cout << "Player " << current_player << " wins!" << endl;
                game_over = true;
            } else if (moves == N * N) {
                // If all moves are done and no one wins, it's a tie
                cout << "It's a tie!" << endl;
                game_over = true;
            } else {
                // Switch players
                current_player = (current_player == 'X') ? 'O' : 'X';
            }
        } else {
            cout << "Invalid move! Try again." << endl;
        }
    }

    return 0;
}
