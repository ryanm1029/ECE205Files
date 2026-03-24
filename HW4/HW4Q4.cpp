#include <iostream>

using namespace std;

// Function to display the Tic-Tac-Toe board
void displayBoard(char board[]) {
    cout << "\nGame Board:\n";
    cout << board[0] << " " << board[1] << " " << board[2] << endl;
    cout << board[3] << " " << board[4] << " " << board[5] << endl;
    cout << board[6] << " " << board[7] << " " << board[8] << endl;
    cout << endl;
}

// Function to check if the current player has won
bool checkWin(char board[], char player) {
    // Array of winning combinations (indices of the board)
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };
    
    for (int i = 0; i < 8; ++i) {
        if (board[wins[i][0]] == player &&
            board[wins[i][1]] == player &&
            board[wins[i][2]] == player) {
            return true;
        }
    }
    return false;
}

int main() {
    // 1D Array to represent 3x3 board
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    int turn = 0;
    char currentPlayer = 'X';
    bool won = false;

    cout << "--- Tic-Tac-Toe ---\n";

    // Play loop: max 9 turns
    while (turn < 9 && !won) {
        displayBoard(board);
        int choice;
        
        cout << "Player " << currentPlayer << ", enter a position (1-9): ";
        cin >> choice;

        // Check range and availability
        if (choice < 1 || choice > 9 || board[choice - 1] == 'X' || board[choice - 1] == 'O') {
            cout << "Invalid move or position taken. Try again.\n";
            continue;
        }

        // Update board and check for a win condition
        board[choice - 1] = currentPlayer;
        won = checkWin(board, currentPlayer);

        if (won) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
        } else {
            // Next turn, swap player
            turn++;
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

    // If max turns reached and no winner, it's a draw
    if (!won) {
        displayBoard(board);
        cout << "It's a draw!\n";
    }

    return 0;
}