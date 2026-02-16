#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double m1, m2, d, f;
    char userChoice;
    double calculateForce(double m1, double m2, double d);

    do {
        //getting variable input from user
        cout << "Please enter a value for m1 in kilograms:" << endl;
        cin >> m1;
        cout << "Please enter a value for m2 in kilograms:" << endl;
        cin >> m2;
        cout << "Please enter a value for d in meters:" << endl;
        cin >> d;

        //calculating and outputting force
        f = calculateForce(m1*1000, m2*1000, d*100);
        cout << "Gravitational force between masses m1 and m2 is: " << f << " dynes" << endl;

        //prompt user for new variables
        cout << "Do you want to calculate again? (y/n): ";
        cin >> userChoice;
    } while (userChoice == 'y' || userChoice == 'Y');
    return 0;
}

double calculateForce(double m1, double m2, double d) {

    const double bigG = 6.673e-8;
    
    double f = bigG * m1 * m2 / pow(d, 2);

    return f;
}