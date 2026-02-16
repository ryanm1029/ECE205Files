#include <iostream>
using namespace std;

// Function Prototypes
double calculateHatSize(double weight, double height);
double calculateJacketSize(double weight, double height, int age);
double calculateWaistSize(double weight, int age);

int main() {
    double height, weight;
    int age;

    // Get user input
    cout << "Enter height in inches: ";
    cin >> height;
    cout << "Enter weight in pounds: ";
    cin >> weight;
    cout << "Enter age in years: ";
    cin >> age;

    // Calculate sizes
    double hatSize = calculateHatSize(weight, height);
    double jacketSize = calculateJacketSize(weight, height, age);
    double waistSize = calculateWaistSize(weight, age);

    // Output formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // Display results
    cout << "\n--- Clothing Size Calculator ---" << endl;
    cout << "Hat Size:    " << hatSize << endl;
    cout << "Jacket Size: " << jacketSize << " inches" << endl;
    cout << "Waist Size:  " << waistSize << " inches" << endl;

    return 0;
}

// Hat size = 2.9 * weight / height
double calculateHatSize(double weight, double height) {
    return 2.9 * (weight / height);
}

// Jacket size logic with age adjustment
double calculateJacketSize(double weight, double height, int age) {
    double size = (height * weight) / 288.0;
    
    // Adjust 1/8 inch for every 10 years over 30
    if (age > 30) {
        int intervals = (age - 30) / 10; // Integer division drops decimals
        size += intervals * (1.0 / 8.0);
    }
    return size;
}

// Waist size logic with age adjustment
double calculateWaistSize(double weight, int age) {
    double size = weight / 5.7;

    // Adjust 1/10 inch for every 2 years over 28
    if (age > 28) {
        int intervals = (age - 28) / 2; // Integer division drops decimals
        size += intervals * (1.0 / 10.0);
    }
    return size;
}