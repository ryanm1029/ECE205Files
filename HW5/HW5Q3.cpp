#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Constants for Pizza type and size
const int DEEP_DISH = 0;
const int HAND_TOSSED = 1;
const int PAN = 2;

const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

// Pizza class definition
class Pizza {
private:
    int type;
    int size;
    int pepperoniToppings;
    int cheeseToppings;

public:
    void setType(int t);
    void setSize(int s);
    void setPepperoniToppings(int p);
    void setCheeseToppings(int c);

    void outputDescription();
    double computePrice();
};

//Pizza function definitions

void Pizza::setType(int t) { type = t; }
void Pizza::setSize(int s) { size = s; }
void Pizza::setPepperoniToppings(int p) { pepperoniToppings = p; }
void Pizza::setCheeseToppings(int c) { cheeseToppings = c; }

void Pizza::outputDescription() {
    string sizeStr = (size == SMALL) ? "Small" : (size == MEDIUM) ? "Medium" : "Large";
    string typeStr = (type == DEEP_DISH) ? "Deep Dish" : (type == HAND_TOSSED) ? "Hand Tossed" : "Pan";

    cout << sizeStr << " " << typeStr << " Pizza with " 
         << pepperoniToppings << " pepperoni and " 
         << cheeseToppings << " cheese toppings";
}

double Pizza::computePrice() {
    double basePrice = (size == SMALL) ? 10.0 : (size == MEDIUM) ? 14.0 : 17.0;
    return basePrice + (2.0 * pepperoniToppings) + (2.0 * cheeseToppings);
}

// Order class definition
class Order {
private:
    vector<Pizza> pizzas;

public:
    void addPizza(Pizza p);
    void outputOrder();
};

// order function definitions

void Order::addPizza(Pizza p) {
    pizzas.push_back(p);
}

void Order::outputOrder() {
    double total = 0.0;
    cout << "--- Customer Order ---" << endl;
    for (size_t i = 0; i < pizzas.size(); i++) {
        cout << i + 1 << ". ";
        pizzas[i].outputDescription();
        double price = pizzas[i].computePrice();
        cout << " - $" << price << endl;
        total += price;
    }
    cout << "----------------------" << endl;
    cout << "Total Price: $" << total << endl;
}

// Main tests

int main() {
    Order myOrder;

    Pizza p1;
    p1.setSize(MEDIUM);
    p1.setType(PAN);
    p1.setPepperoniToppings(2);
    p1.setCheeseToppings(0);

    Pizza p2;
    p2.setSize(LARGE);
    p2.setType(DEEP_DISH);
    p2.setPepperoniToppings(0);
    p2.setCheeseToppings(3);

    myOrder.addPizza(p1);
    myOrder.addPizza(p2);

    myOrder.outputOrder();

    return 0;
}