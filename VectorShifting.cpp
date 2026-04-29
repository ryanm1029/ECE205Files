#include <iostream>
#include <vector>
using namespace std;

// This function takes a vector by REFERENCE (&) so we modify the original.
// It searches for a specific value, deletes it, and manually shifts everything left.
void removeValueAndShift(vector<char>& vec, char target) {
    for (int i = 0; i < vec.size(); i++) {
        
        // If we found the character we want to delete
        if (vec[i] == target) {
            
            // MANUAL SHIFT:
            // Start at the index we want to delete, and overwrite it with 
            // the item immediately to its right. Keep doing this to the end.
            for (int j = i; j < vec.size() - 1; j++) {
                vec[j] = vec[j + 1]; 
            }
            
            // Now that everything shifted left, the last item is a duplicate.
            // Pop it off the back to actually shrink the vector size.
            vec.pop_back();

            // CRUCIAL: Because everything shifted left, a new unchecked item 
            // just slid into our current index 'i'. We must decrement 'i' 
            // so the outer loop checks this spot again!
            i--; 
        }
    }
}

int main() {
    vector<char> letters = {'a', 'b', 'x', 'x', 'c', 'x', 'd'};

    cout << "Original: ";
    for (char c : letters) cout << c << " ";
    cout << endl;

    // Call the function (modifies 'letters' directly due to pass-by-reference)
    removeValueAndShift(letters, 'x');

    cout << "After removing 'x': ";
    for (char c : letters) cout << c << " ";
    cout << endl;

    return 0;
}