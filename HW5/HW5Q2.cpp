#include <iostream>
#include <string>

using namespace std;

// Constants for Pizza type
const int DEEP_DISH = 0;
const int HAND_TOSSED = 1;
const int PAN = 2;

// Constants for Pizza size
const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

class Pizza {
private:
    int type;
    int size;
    int pepperoniToppings;
    int cheeseToppings;

public:
    // Mutators
    void setType(int t);
    void setSize(int s);
    void setPepperoniToppings(int p);
    void setCheeseToppings(int c);

    // Accessors
    int getType();
    int getSize();
    int getPepperoniToppings();
    int getCheeseToppings();

    // Output and price calculation
    void outputDescription();
    double computePrice();
};

// function definitions

void Pizza::setType(int t) {
    type = t;
}

void Pizza::setSize(int s) {
    size = s;
}

void Pizza::setPepperoniToppings(int p) {
    pepperoniToppings = p;
}

void Pizza::setCheeseToppings(int c) {
    cheeseToppings = c;
}

int Pizza::getType() {
    return type;
}

int Pizza::getSize() {
    return size;
}

int Pizza::getPepperoniToppings() {
    return pepperoniToppings;
}

int Pizza::getCheeseToppings() {
    return cheeseToppings;
}

void Pizza::outputDescription() {
    string sizeStr = "";
    string typeStr = "";

    if (size == SMALL) sizeStr = "Small";
    else if (size == MEDIUM) sizeStr = "Medium";
    else if (size == LARGE) sizeStr = "Large";

    if (type == DEEP_DISH) typeStr = "Deep Dish";
    else if (type == HAND_TOSSED) typeStr = "Hand Tossed";
    else if (type == PAN) typeStr = "Pan";

    cout << sizeStr << " " << typeStr << " Pizza with " 
         << pepperoniToppings << " pepperoni topping(s) and " 
         << cheeseToppings << " cheese topping(s).";
}

double Pizza::computePrice() {
    double basePrice = 0.0;
    
    if (size == SMALL) basePrice = 10.0;
    else if (size == MEDIUM) basePrice = 14.0;
    else if (size == LARGE) basePrice = 17.0;

    return basePrice + (2.0 * pepperoniToppings) + (2.0 * cheeseToppings);
}

// Main tests

int main() {
    Pizza p1;
    p1.setSize(SMALL);
    p1.setType(HAND_TOSSED);
    p1.setPepperoniToppings(1);
    p1.setCheeseToppings(1);

    Pizza p2;
    p2.setSize(LARGE);
    p2.setType(DEEP_DISH);
    p2.setPepperoniToppings(2);
    p2.setCheeseToppings(3);

    cout << "Pizza 1: ";
    p1.outputDescription();
    cout << "\nPrice: $" << p1.computePrice() << "\n\n";

    cout << "Pizza 2: ";
    p2.outputDescription();
    cout << "\nPrice: $" << p2.computePrice() << "\n";

    return 0;
}