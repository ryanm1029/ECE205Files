#include <iostream>
#include <fstream> // REQUIRED for File I/O
#include <string>
using namespace std;

int main() {
    string filename = "histogram_data.txt";

    // -----------------------------------------
    // 1. WRITING TO A FILE (ofstream = Output File Stream)
    // -----------------------------------------
    ofstream myFileOut(filename); // Opens or creates the file

    // Always check if the file opened successfully!
    if (myFileOut.is_open()) {
        
        // Write to it exactly like you use 'cout'
        myFileOut << "Bin 1 (0-9): 5\n";
        myFileOut << "Bin 2 (10-19): 12\n";
        myFileOut << "Bin 3 (20-29): 8\n";
        
        myFileOut.close(); // ALWAYS close the file when done
        cout << "Successfully wrote to " << filename << endl;
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }


    // -----------------------------------------
    // 2. READING FROM A FILE (ifstream = Input File Stream)
    // -----------------------------------------
    ifstream myFileIn(filename); // Opens the file for reading

    if (myFileIn.is_open()) {
        string line;
        
        cout << "\n--- Reading data back from file ---\n";
        
        // getline() grabs an entire line of text until it hits a newline (\n)
        // It returns false when it reaches the end of the file.
        while (getline(myFileIn, line)) {
            cout << line << endl; // Print the line to the console
        }
        
        myFileIn.close();
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }

    return 0;
}