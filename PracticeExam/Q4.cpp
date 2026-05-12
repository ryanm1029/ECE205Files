#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // 1. Open the file
    ifstream inFile("data.txt"); 

    // 2. ALWAYS check if it actually opened
    if (!inFile) {
        cout << "Error: Could not open file!" << endl;
        return 1; // Exit with error
    }

    string name;
    int score;

    // 3. Read data until you hit the end of the file. 
    // This loop automatically stops when there is no more data.
    while (inFile >> name >> score) {
        cout << "Read: " << name << " got a " << score << endl;
    }

    // 4. Close the file
    inFile.close(); 
    return 0;
}