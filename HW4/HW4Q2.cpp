#include <iostream>

using namespace std;

// Function to get and validate the degree of difficulty
double getValidDifficulty() {
    double diff;
    do {
        cout << "Enter degree of difficulty (1.2 to 3.8): ";
        cin >> diff;
        if (diff < 1.2 || diff > 3.8) {
            cout << "Invalid input. Must be between 1.2 and 3.8.\n";
        }
    } while (diff < 1.2 || diff > 3.8);
    return diff;
}

// Function to get and validate the 7 judges' scores
void getValidScores(double scores[], int size) {
    for(int i = 0; i < size; ++i) {
        do {
            cout << "Enter score for judge " << i + 1 << " (0 to 10): ";
            cin >> scores[i];
            if (scores[i] < 0 || scores[i] > 10) {
                cout << "Invalid input. Must be between 0 and 10.\n";
            }
        } while (scores[i] < 0 || scores[i] > 10);
    }
}

// Function to calculate the final score according to the rules
double calculateFinalScore(double scores[], int size, double difficulty) {
    double min_score = scores[0];
    double max_score = scores[0];
    double sum = 0;

    // Find the min, max, and total sum simultaneously
    for(int i = 0; i < size; ++i) {
        if (scores[i] < min_score) min_score = scores[i];
        if (scores[i] > max_score) max_score = scores[i];
        sum += scores[i];
    }

    // Throw out the highest and lowest scores
    sum = sum - min_score - max_score;
    
    // Apply final multiplier
    return sum * difficulty * 0.6;
}

int main() {
    const int NUM_JUDGES = 7;
    double scores[NUM_JUDGES];
    
    cout << "--- Diving Competition Scorer ---\n";
    
    double difficulty = getValidDifficulty();
    getValidScores(scores, NUM_JUDGES);
    
    double finalScore = calculateFinalScore(scores, NUM_JUDGES, difficulty);
    
    cout << "\nThe diver's final score is: " << finalScore << endl;
    
    return 0;
}