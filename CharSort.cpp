#include <iostream>
#include <vector>

using namespace std;

// Function to delete repeated characters and manually shift remaining elements left
void deleteRepeatedChars(vector<char>& myVector) {
    for (int i = 0; i < myVector.size(); i++) {
        // Compare the current character (i) to all the characters AFTER it (j)
        for (int j = i + 1; j < myVector.size(); ) {
            
            if (myVector[i] == myVector[j]) {
                // We found a duplicate! Now we must manually shift elements down by 1.
                // We start at 'j' (the duplicate) and overwrite it with the next element.
                for (int k = j; k < myVector.size() - 1; k++) {
                    myVector[k] = myVector[k + 1];
                }
                
                // Pop the last element off because everything shifted left
                myVector.pop_back();
                
                // IMPORTANT: Do NOT increment 'j' here, because a new, unchecked 
                // character just shifted into the 'j' spot.
            } else {
                // If it wasn't a duplicate, it's safe to move to the next character
                j++;
            }
        }
    }
}

// Function to sort characters in decreasing order (z to a)
void selectionSort(vector<char>& myVector) {
    int n = myVector.size();
    
    for (int i = 0; i < n - 1; i++) {
        // Since we want decreasing order, we look for the MAXIMUM element
        int maxIndex = i;
        
        for (int j = i + 1; j < n; j++) {
            if (myVector[j] > myVector[maxIndex]) { // Notice the > instead of <
                maxIndex = j;
            }
        }
        
        // Swap the found maximum element with the element at index i
        char temp = myVector[maxIndex];
        myVector[maxIndex] = myVector[i];
        myVector[i] = temp;
    }
}

int main() {
    vector<char> charList;
    char input;

    cout << "Enter characters one at a time. Enter '0' to stop." << endl;

    while (true) {
        cout << "Enter character: ";
        cin >> input;

        // Stop condition based on homework instructions
        if (input == '0') {
            break;
        }

        charList.push_back(input);
    }

    cout << "\nOriginal Vector: ";
    for (char c : charList) cout << c << " ";
    cout << endl;

    // 1. Delete the repeats
    deleteRepeatedChars(charList);
    
    // 2. Sort z to a
    selectionSort(charList);

    cout << "Processed Vector (No repeats, sorted z to a): ";
    for (char c : charList) cout << c << " ";
    cout << endl;

    return 0;
}