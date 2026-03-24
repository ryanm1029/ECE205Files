#include <iostream>
#include <cctype> // For toupper()

using namespace std;

// Function to display the current seating chart
void displaySeats(char seats[][4], int rows) {
    cout << "\nCurrent Seating Chart:\n";
    for (int i = 0; i < rows; ++i) {
        cout << i + 1 << "\t";
        for (int j = 0; j < 4; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    const int ROWS = 10;
    const int COLS = 4;
    char seats[ROWS][COLS];

    // Initialize the seats to default letters A, B, C, D
    for (int i = 0; i < ROWS; ++i) {
        seats[i][0] = 'A';
        seats[i][1] = 'B';
        seats[i][2] = 'C';
        seats[i][3] = 'D';
    }

    char continueChoice = 'Y';
    int totalSeats = ROWS * COLS;
    int takenSeats = 0;

    while (toupper(continueChoice) == 'Y' && takenSeats < totalSeats) {
        displaySeats(seats, ROWS);
        
        int row;
        char seatChar;
        cout << "Enter desired seat (e.g. '2 B'): ";
        cin >> row >> seatChar;

        seatChar = toupper(seatChar);
        int col = seatChar - 'A'; // Convert char to column index (0-3)

        // Validate the inputted row and column
        if (row < 1 || row > ROWS || col < 0 || col >= COLS) {
            cout << "Invalid seat selection. Please try again.\n";
            continue;
        }

        // Check if the seat is already taken
        if (seats[row - 1][col] == 'X') {
            cout << "Seat is already taken. Please choose another.\n";
        } else {
            // Assign the seat
            seats[row - 1][col] = 'X';
            takenSeats++;
            cout << "Seat successfully reserved.\n";
            
            displaySeats(seats, ROWS);

            // Ask if user wants to continue
            if (takenSeats < totalSeats) {
                cout << "Do you want to continue adding seats? (Y/N): ";
                cin >> continueChoice;
            } else {
                cout << "All seats are taken! The plane is full.\n";
            }
        }
    }
    
    cout << "Exiting ticketing system.\n";
    return 0;
}