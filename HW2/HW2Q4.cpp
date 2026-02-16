#include <iostream>
#include <cstdlib>
#include <ctime>  

using namespace std;

// Function prototypes
bool alreadySelected(int winners[], int currentCount, int candidate);
void pickWinners(int winners[], int numWinners, int poolSize);

int main() {
    // Seed the random number generator so it changes every run
    srand(time(0));

    const int NUM_PRIZES = 4;
    const int POOL_SIZE = 25;
    int winners[NUM_PRIZES];

    // Select the winners
    pickWinners(winners, NUM_PRIZES, POOL_SIZE);

    // Output results
    cout << "--- Prize Winners ---" << endl;
    for (int i = 0; i < NUM_PRIZES; i++) {
        cout << "Winner " << (i + 1) << ": Finalist #" << winners[i] << endl;
    }

    return 0;
}

// Helper function to check for duplicates
bool alreadySelected(int winners[], int currentCount, int candidate) {
    for (int i = 0; i < currentCount; i++) {
        if (winners[i] == candidate) {
            return true; // Found a duplicate
        }
    }
    return false; // Unique
}

// Function to fill the array with unique random numbers
void pickWinners(int winners[], int numWinners, int poolSize) {
    int count = 0;
    
    while (count < numWinners) {
        // Generate random number between 1 and poolSize
        int candidate = rand() % poolSize + 1;

        // Only add if not already in the list
        if (!alreadySelected(winners, count, candidate)) {
            winners[count] = candidate;
            count++;
        }
    }
}