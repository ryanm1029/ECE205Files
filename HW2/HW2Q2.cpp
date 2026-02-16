#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Function Prototypes
double calculateAverage(double scores[], int size);
double calculateStdDev(double scores[], int size, double average);

int main() {
    const int NUM_SCORES = 5;
    double scores[NUM_SCORES];
    
    // 1. Open the input file
    ifstream inputFile("scores.txt");
    
    // Check if file exists
    if (!inputFile.is_open()) {
        cout << "Error: Unable to open scores.txt" << endl;
        return 1;
    }

    // Read the 5 scores into array
    for (int i = 0; i < NUM_SCORES; i++) {
        inputFile >> scores[i];
    }
    
    inputFile.close(); // Done reading, close the file

    // 2. Perform Calculations
    double average = calculateAverage(scores, NUM_SCORES);
    double stdDev = calculateStdDev(scores, NUM_SCORES, average);

    // 3. Output to Console
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2); 

    cout << "--- Exam Statistics ---" << endl;
    cout << "Average Score:      " << average << endl;
    cout << "Standard Deviation: " << stdDev << endl;

    // 4. Output to File (output.txt)
    ofstream outputFile("output.txt");
    
    // set precision for the file stream separately
    outputFile.setf(ios::fixed);
    outputFile.setf(ios::showpoint);
    outputFile.precision(2);

    outputFile << "Average Score: " << average << endl;
    outputFile << "Standard Deviation: " << stdDev << endl;
    
    outputFile.close();
    cout << "Results have been written to output.txt" << endl;

    return 0;
}

// Function to calculate the mean
double calculateAverage(double scores[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += scores[i];
    }
    return sum / size;
}

// Function to calculate Standard Deviation
double calculateStdDev(double scores[], int size, double average) {
    double sumOfSquares = 0.0;
    
    for (int i = 0; i < size; i++) {
        // Find difference from mean, square it, add to sum
        sumOfSquares += pow((scores[i] - average), 2);
    }
    
    // Divide by N
    double variance = sumOfSquares / size;
    
    return sqrt(variance);
}