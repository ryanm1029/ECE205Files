#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// --- FIND MAX / MIN IN A VECTOR ---
// ==========================================
// Useful for finding bounds (e.g., Histogram bins from HW 6)
int findMax(const vector<int>& vec) {
    if (vec.empty()) return 0; // Guard against empty vector
    
    int maxVal = vec[0]; // Assume first element is the biggest
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] > maxVal) {
            maxVal = vec[i]; // Found a new biggest, update it
        }
    }
    return maxVal;
}

// ==========================================
// --- SELECTION SORT ---
// ==========================================
// Sorts by finding the smallest element and swapping it to the front.
// (Modify the '<' to '>' to sort in descending/decreasing order like HW 6)
void selectionSort(vector<char>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        
        // Find the index of the minimum element in the unsorted portion
        for (int j = i + 1; j < n; j++) {
            if (vec[j] < vec[minIndex]) { 
                minIndex = j;
            }
        }
        // Swap the found minimum element with the first unsorted element
        char temp = vec[i];
        vec[i] = vec[minIndex];
        vec[minIndex] = temp;
    }
}

// ==========================================
// --- BUBBLE SORT ---
// ==========================================
// The easiest sort to memorize. Pushes the largest values to the end.
void bubbleSort(vector<int>& vec) {
    int n = vec.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vec[j] > vec[j + 1]) {
                // Swap them if they are in the wrong order
                int temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}

// ==========================================
// --- REMOVE DUPLICATES (MANUAL SHIFTING) ---
// ==========================================
// From HW 6: Scans for copies, shifts all higher elements down, and resizes.
void deleteRepeatedChars(vector<char>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            
            // If a duplicate is found
            if (vec[i] == vec[j]) {
                // Shift all elements AFTER 'j' down by 1 to overwrite it
                for (int k = j; k < vec.size() - 1; k++) {
                    vec[k] = vec[k + 1];
                }
                // Shrink the vector size by 1
                vec.pop_back(); 
                
                // Decrement j so we don't skip the new element that just shifted into j's spot
                j--; 
            }
        }
    }
}

// ==========================================
// --- LINEAR SEARCH ---
// ==========================================
// Checks every single element one by one. Works on unsorted data.
int linearSearch(const vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == target) {
            return i; // Target found, return its index
        }
    }
    return -1; // Target not found
}

// ==========================================
// --- BINARY SEARCH ---
// ==========================================
// MUCH faster, but ONLY works if the vector is ALREADY SORTED.
int binarySearch(const vector<int>& vec, int target) {
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (vec[mid] == target) 
            return mid;             // Found it!
        else if (vec[mid] < target) 
            left = mid + 1;         // Search the right half
        else 
            right = mid - 1;        // Search the left half
    }
    return -1; // Not found
}

// ==========================================
// --- SIEVE OF ERATOSTHENES (PRIMES) ---
// ==========================================
// From HW 6: An extremely efficient way to find all prime numbers up to 'n'.
void sieveOfEratosthenes(int n) {
    // Create a boolean vector of size n+1, initialize all to true
    vector<bool> primes(n + 1, true);
    
    // 0 and 1 are not prime numbers
    primes[0] = false;
    primes[1] = false;

    // Start at 2, go up to the square root of n
    for (int p = 2; p * p <= n; p++) {
        // If primes[p] is still true, it is a prime
        if (primes[p] == true) {
            // Mark all multiples of p as false (not prime)
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
    }

    // Print all remaining true values (the primes!)
    cout << "Primes up to " << n << ": ";
    for (int p = 2; p <= n; p++) {
        if (primes[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}


int main() {
    // Example usage of the algorithms above
    vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};
    vector<char> letters = {'a', 'b', 'a', 'c', 'b', 'z'};

    cout << "Max value is: " << findMax(numbers) << endl;

    bubbleSort(numbers);
    cout << "After Bubble Sort, index of 25 is: " << binarySearch(numbers, 25) << endl;

    deleteRepeatedChars(letters);
    selectionSort(letters);
    
    sieveOfEratosthenes(30);

    return 0;
}