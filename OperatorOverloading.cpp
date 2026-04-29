#include <iostream>
using namespace std;

class MyNumber {
private:
    int value;

public:
    // Constructor
    MyNumber(int v = 0) { value = v; }

    // 1. Overloading math operators (+)
    // Returns a NEW object, doesn't change the original
    MyNumber operator+(const MyNumber& other) {
        return MyNumber(this->value + other.value);
    }

    // 2. Overloading Prefix ++ (++num)
    // Modifies the original object, returns it by reference (&)
    MyNumber& operator++() {
        value += 1;
        return *this; // '*this' means "the object that called this function"
    }

    // 3. Overloading Postfix ++ (num++)
    // Takes a dummy 'int' parameter so the compiler knows it's postfix
    MyNumber operator++(int) {
        MyNumber temp = *this; // Save the old state
        value += 1;            // Update the current state
        return temp;           // Return the old state
    }

    // 4. Friend function to overload cout <<
    // 'friend' means it is NOT a member of the class, but it gets VIP access to private variables.
    // It must return ostream& so you can chain it (e.g., cout << a << b;)
    friend ostream& operator<<(ostream& out, const MyNumber& num);
};

// Implementation of the friend function (notice no "MyNumber::" prefix because it's a friend, not a member)
ostream& operator<<(ostream& out, const MyNumber& num) {
    out << "[" << num.value << "]";
    return out;
}

int main() {
    MyNumber a(10);
    MyNumber b(5);

    cout << "Initial a: " << a << endl; // Uses our overloaded << friend!

    MyNumber c = a + b; // Uses our overloaded +
    cout << "a + b = " << c << endl;

    cout << "Prefix ++a: " << ++a << endl; // Becomes 11, then prints 11
    
    // Postfix: prints 11, then becomes 12 in the background
    cout << "Postfix a++: " << a++ << endl; 
    cout << "a is now: " << a << endl;      // Prints 12

    return 0;
}