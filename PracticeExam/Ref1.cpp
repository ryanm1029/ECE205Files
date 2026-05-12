#include <iostream>
#include <string>
#include <iomanip> // For formatting output (setprecision)

using namespace std;

// ==========================================
// --- FUNCTIONS & PASS-BY-REFERENCE ---
// ==========================================

// Pass-by-value (creates a copy, original stays the same)
void addTen(int val) {
    val += 10; 
}

// Pass-by-reference (modifies the actual original variable)
void addTenRef(int& val) {
    val += 10; 
}

// Function Overloading (Same name, different parameter types)
int multiply(int a, int b) { return a * b; }
double multiply(double a, double b) { return a * b; }

// ==========================================
// --- STRUCTS ---
// ==========================================
// Structs are public by default, good for simple data grouping
struct Point {
    int x;
    int y;
};

// ==========================================
// --- CLASSES & CONSTRUCTORS ---
// ==========================================
class Pizza {
private: // Data is hidden from the outside
    string type;
    int size;

public: // Functions are accessible from the outside
    
    // 1. Default Constructor (No arguments)
    Pizza() {
        type = "Cheese";
        size = 10;
    }

    // 2. Parameterized Constructor (Allows setting data immediately)
    Pizza(string t, int s) {
        type = t;
        size = s;
    }

    // 3. Mutator (Setter) - Changes private data
    void setType(string t) {
        type = t;
    }

    // 4. Accessor (Getter) - Reads private data
    string getType() const {
        return type;
    }
};

int main() {
    
    // ==========================================
    // --- CONSOLE I/O & FORMATTING ---
    // ==========================================
    {
        double pi = 3.14159265;
        // Forces 2 decimal places (requires <iomanip>)
        cout << fixed << setprecision(2);
        cout << "Formatted PI: " << pi << endl; // Prints 3.14
    }

    // ==========================================
    // --- STRINGS & CONVERSIONS ---
    // ==========================================
    {
        // Reading a full line with spaces
        string fullName;
        // cin >> fullName; // <--- This would stop at the first space
        // getline(cin, fullName); // <--- Use this for names/sentences

        // String to Integer/Double (Requires <string>)
        int age = stoi("25");
        double GPA = stod("3.85");

        // Number to String
        string ageStr = to_string(age);
        string gpaStr = to_string(GPA);
    }

    // ==========================================
    // --- STATIC ARRAYS ---
    // ==========================================
    {
        // Initialization
        int staticArr[5] = {10, 20, 30, 40, 50};
        
        // Size calculation trick for static arrays
        int size = sizeof(staticArr) / sizeof(staticArr[0]);
    }

    // ==========================================
    // --- POINTERS & REFERENCES ---
    // ==========================================
    {
        int num = 100;
        int* ptr = &num; // ptr holds the memory address of num

        // *ptr dereferences the pointer to get/change the actual value
        *ptr = 200; // num is now 200
        
        // Pointers to Objects use the Arrow Operator (->)
        Pizza myPizza("Pepperoni", 12);
        Pizza* pizzaPtr = &myPizza;
        string t = pizzaPtr->getType(); // Arrow instead of dot (.)
    }

    // ==========================================
    // --- 1D DYNAMIC ARRAYS ---
    // ==========================================
    {
        int size = 5;
        // ALLOCATION: Create array on the heap using 'new'
        int* dynArray = new int[size];

        // Assign values
        for(int i = 0; i < size; i++) {
            dynArray[i] = i * 10;
        }

        // DEALLOCATION: Must delete[] to prevent memory leaks
        delete[] dynArray;
    }

    // ==========================================
    // --- 2D DYNAMIC ARRAYS ---
    // ==========================================
    {
        int rows = 3;
        int cols = 4;

        // ALLOCATION: Step 1 - Array of Row Pointers
        int** grid = new int*[rows];

        // ALLOCATION: Step 2 - Allocate Columns for each Row
        for (int i = 0; i < rows; i++) {
            grid[i] = new int[cols];
        }

        // DEALLOCATION: Step 1 - Delete Columns first!
        for (int i = 0; i < rows; i++) {
            delete[] grid[i];
        }

        // DEALLOCATION: Step 2 - Delete the array of row pointers
        delete[] grid;
    }

    return 0;
}