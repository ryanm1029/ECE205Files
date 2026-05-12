#include <iostream>
#include <fstream>   // For File I/O
#include <vector>    // For STL Vectors
#include <stack>     // For STL Stacks
#include <queue>     // For STL Queues
#include <algorithm> // For std::sort
#include <string>

using namespace std;

// =========================================================
// --- STATIC, INHERITANCE & POLYMORPHISM (VIRTUAL) ---
// =========================================================

class Robot {
protected: // Accessible to child classes, hidden from outside
    string name;

public:
    // Static Variable Declaration (Shared by all Robot objects)
    static int totalRobots; 

    Robot(string n) {
        name = n;
        totalRobots++;
    }

    // Virtual Function: Tells C++ to check for Child overrides at runtime
    virtual void operate() { 
        cout << "Robot is doing a generic task." << endl; 
    }
};

// Static Variable Initialization (MUST be defined outside the class in .cpp)
int Robot::totalRobots = 0;

// Inheritance: WelderBot inherits from Robot
class WelderBot : public Robot {
private:
    int temp;

public:
    // Constructor Delegation: Pass data up to Parent constructor
    WelderBot(string n, int t) : Robot(n) {
        temp = t;
    }

    // Override the parent's virtual function
    void operate() override { 
        cout << name << " is welding at " << temp << " degrees." << endl; 
    }

    // ==========================================
    // --- OPERATOR OVERLOADING & FRIENDS ---
    // ==========================================
    
    // Member Function Overload (+): Adds two objects together
    WelderBot operator+(WelderBot botB) {
        int avgTemp = (this->temp + botB.temp) / 2;
        return WelderBot(this->name + "-" + botB.name, avgTemp);
    }

    // Friend Function: Grants external function access to private data ('temp')
    friend ostream& operator<<(ostream& out, const WelderBot& w);
};

// Global implementation of the friend function (NO 'WelderBot::' prefix!)
ostream& operator<<(ostream& out, const WelderBot& w) {
    out << "WelderBot " << w.name << " (Temp: " << w.temp << ")";
    return out;
}

// ==========================================
// --- TEMPLATES ---
// ==========================================

// Function Template: Works for int, double, string, etc.
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Class Template
template <typename T>
class Box {
private:
    T contents;
public:
    Box(T val) { contents = val; }
    T getContents() { return contents; }
};

// ==========================================
// --- LINKED LISTS & BINARY TREES ---
// ==========================================

// Linked List Node
struct ListNode {
    int data;
    ListNode* next;
};

// Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
};

// ==========================================
// --- CUSTOM COMPARATOR (For STL Sort) ---
// ==========================================
// Returns true if 'a' should go before 'b'
bool compareDescending(int a, int b) {
    return a > b; // Descending order (largest first)
}


int main() {

    // ==========================================
    // --- FILE I/O (<fstream>) ---
    // ==========================================
    {
        // 1. WRITING TO A FILE (ofstream)
        ofstream outFile("data.txt");
        if (outFile.is_open()) {
            outFile << "Alice 95" << endl;
            outFile << "Bob 82" << endl;
            outFile.close(); // ALWAYS close the file!
        }

        // 2. READING FROM A FILE (ifstream)
        ifstream inFile("data.txt");
        string stuName;
        int stuScore;

        if (inFile.is_open()) {
            // Extracts data sequentially, skipping whitespace/newlines automatically
            while (inFile >> stuName >> stuScore) {
                // Do something with the data
            }
            inFile.close();
        }
    }

    // ==========================================
    // --- STL VECTOR (<vector>) ---
    // ==========================================
    {
        vector<int> nums;
        
        nums.push_back(10); // Adds to end
        nums.push_back(50);
        nums.push_back(30);

        int s = nums.size(); // Returns 3

        // STL Sorting (Requires <algorithm> and a custom comparator function)
        sort(nums.begin(), nums.end(), compareDescending); 
    }

    // ==========================================
    // --- STL STACK (<stack>) - LIFO ---
    // ==========================================
    {
        stack<int> myStack;
        myStack.push(1); // Bottom
        myStack.push(2);
        myStack.push(3); // Top

        while (!myStack.empty()) {
            int current = myStack.top(); // Look at the top (3)
            myStack.pop();               // Remove the top (Destroys 3)
        }
    }

    // ==========================================
    // --- STL QUEUE (<queue>) - FIFO ---
    // ==========================================
    {
        queue<int> myQueue;
        myQueue.push(1); // Front
        myQueue.push(2);
        myQueue.push(3); // Back

        while (!myQueue.empty()) {
            int current = myQueue.front(); // Look at the front (1)
            myQueue.pop();                 // Remove the front (Destroys 1)
        }
    }

    // ==========================================
    // --- POLYMORPHISM & POINTERS IN ACTION ---
    // ==========================================
    {
        // Array of Base Class pointers to hold different Child objects
        Robot* fleet[2] = {nullptr}; 
        
        fleet[0] = new Robot("R2D2");
        fleet[1] = new WelderBot("Sparky", 500);

        // This works because 'operate()' is marked as virtual!
        for (int i = 0; i < 2; i++) {
            fleet[i]->operate(); 
            delete fleet[i]; // Clean up dynamic memory
        }
    }

    // ==========================================
    // --- MANUAL LINKED LIST CREATION ---
    // ==========================================
    {
        ListNode* head = new ListNode{10, nullptr};
        ListNode* second = new ListNode{20, nullptr};
        
        head->next = second; // Link them up

        // Clean up
        delete head;
        delete second;
    }

    return 0;
}