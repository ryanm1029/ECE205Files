#include <iostream>
#include <vector>
using namespace std;

// BASE CLASS
class Pizza {
protected: 
    // 'protected' is like private, but allows derived (child) classes to access it
    double basePrice;

public:
    Pizza(double price) { basePrice = price; }

    // VIRTUAL FUNCTION: The magic word for Polymorphism.
    // It tells C++: "If a child class has a function with this exact same name, 
    // ignore this base version and run the child's version instead."
    virtual void calculatePrice() {
        cout << "Standard Pizza: $" << basePrice << endl;
    }
    
    // Virtual destructor (Always include this if you have virtual functions!)
    virtual ~Pizza() {}
};

// DERIVED CLASS 1
class DeepDish : public Pizza {
public:
    // Call the base class constructor using an initializer list
    DeepDish(double price) : Pizza(price) {}

    // 'override' is optional but good practice. It proves we are replacing the virtual function.
    void calculatePrice() override {
        cout << "Deep Dish (Extra baking time): $" << basePrice + 5.00 << endl;
    }
};

// DERIVED CLASS 2
class ThinCrust : public Pizza {
public:
    ThinCrust(double price) : Pizza(price) {}

    void calculatePrice() override {
        cout << "Thin Crust (Less dough): $" << basePrice - 2.00 << endl;
    }
};

int main() {
    // POLYMORPHISM IN ACTION:
    // We create a vector of POINTERS to the Base Class.
    // This allows us to store different child types in the exact same array!
    vector<Pizza*> myOrder;

    myOrder.push_back(new DeepDish(10.00));
    myOrder.push_back(new ThinCrust(10.00));
    myOrder.push_back(new Pizza(10.00));

    // When we loop through, the program dynamically figures out which 
    // specific 'calculatePrice()' to run based on the actual object type!
    for (int i = 0; i < myOrder.size(); i++) {
        myOrder[i]->calculatePrice(); 
        // Notice we use -> because they are pointers!
    }

    // Cleanup the heap memory
    for (int i = 0; i < myOrder.size(); i++) {
        delete myOrder[i];
    }

    return 0;
}