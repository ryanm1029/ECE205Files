#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum value in the vector so we know how many bins to make
int findMax(const vector<int>& data) {
    int maxVal = 0;
    for (int i = 0; i < data.size(); i++) {
        if (data[i] > maxVal) {
            maxVal = data[i];
        }
    }
    return maxVal;
}

// Function to calculate and display the histogram
void printHistogram(const vector<int>& data) {
    if (data.empty()) {
        cout << "No data was entered." << endl;
        return;
    }

    // Find the highest number to figure out how many bins we need
    int maxVal = findMax(data);
    
    // If max is 25, 25/10 = 2. We need 3 bins (0, 1, 2). So add 1.
    int numBins = (maxVal / 10) + 1; 
    
    // Create a vector of 'numBins' size, all initialized to 0
    vector<int> bins(numBins, 0);

    // Calculate the histogram
    for (int i = 0; i < data.size(); i++) {
        int binIndex = data[i] / 10; // e.g., 25 / 10 = bin 2
        bins[binIndex]++;            // Increment the count for that bin
    }

    // Output the histogram
    cout << "\n--- Histogram ---" << endl;
    for (int i = 0; i < bins.size(); i++) {
        cout << "Bin " << i + 1 << " (" << i * 10 << "..." << (i * 10) + 9 << "): " << bins[i] << " values" << endl;
    }
}

int main() {
    vector<int> numbers;
    int input;

    cout << "Enter non-negative integers for the histogram." << endl;
    cout << "Enter a negative integer to end input." << endl;

    while (true) {
        cout << "Enter number: ";
        cin >> input;

        // Stop condition
        if (input < 0) {
            break;
        }

        numbers.push_back(input);
    }

    // Modularity: Call the function to handle the logic
    printHistogram(numbers);

    return 0;
}