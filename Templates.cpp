#include <iostream>
#include <vector>
using namespace std;

// TEMPLATE FUNCTION
// 'typename T' creates a placeholder data type called 'T'.
// Whenever you call the function, C++ replaces 'T' with whatever type you passed in.
template <typename T>
void printVector(const vector<T>& vec) { // Passed by const reference for speed!
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Another Template Function: A generic swap!
template <typename T>
void mySwap(T& a, T& b) { // MUST pass by reference (&) to swap original values
    T temp = a;
    a = b;
    b = temp;
}

// TEMPLATE CLASS
// Same concept, but for a whole class.
template <typename T>
class StorageBox {
private:
    T item; // The item can be any type
public:
    StorageBox(T i) { item = i; }
    T getItem() { return item; }
};

int main() {
    // 1. Using Template Functions
    vector<int> intVec = {1, 2, 3};
    vector<char> charVec = {'a', 'b', 'c'};

    cout << "Ints: ";
    printVector(intVec);   // Automatically figures out T is 'int'
    
    cout << "Chars: ";
    printVector(charVec);  // Automatically figures out T is 'char'

    double num1 = 5.5, num2 = 9.9;
    mySwap(num1, num2);    // Swaps the doubles
    cout << "Swapped doubles: " << num1 << ", " << num2 << endl;

    // 2. Using Template Classes
    // For classes, you MUST explicitly state the type in angle brackets < >
    StorageBox<string> myWordBox("Hello");
    StorageBox<int> myNumberBox(100);

    cout << "Box holds: " << myWordBox.getItem() << endl;

    return 0;
}