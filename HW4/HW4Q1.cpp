#include <iostream>

using namespace std;

// Function to calculate and print the histogram
void calculateHistogram(int arr[], int size) {
    int max_val = arr[0];
    for(int i = 1; i < size; ++i) {
        if(arr[i] > max_val) max_val = arr[i];
    }

    int num_bins = (max_val / 10) + 1;
    int bins[100] = {0}; // Static array for bins assuming max 100 bins

    for(int i = 0; i < size; ++i) {
        bins[arr[i] / 10]++;
    }

    cout << "\nHistogram Data:" << endl;
    for(int i = 0; i < num_bins; ++i) {
        cout << "Bin " << i + 1 << " (" << i * 10 << "..." << i * 10 + 9 << "): " << bins[i] << endl;
    }
}

int main() {
    const int MAX_SIZE = 100; 
    int arr[MAX_SIZE];
    int user_size;
    
    cout << "How many integers will you enter? (Max 100): ";
    cin >> user_size;

    // validation to stay within the array bounds
    if (user_size > MAX_SIZE || user_size <= 0) {
        cout << "Invalid size." << endl;
        return 1;
    }

    cout << "Enter " << user_size << " non-negative integers:\n";
    for(int i = 0; i < user_size; ++i) {
        cin >> arr[i];
        
        // Enforce non-negative requirement
        while(arr[i] < 0) {
            cout << "Value must be non-negative. Re-enter: ";
            cin >> arr[i];
        }
    }

    calculateHistogram(arr, user_size);

    return 0;
}