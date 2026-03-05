#include <iostream>
#include <cmath>

using namespace std;

// Function declaration
void computeTriangle(double a, double b, double c, double& area, double& perimeter);

int main() 
{
    double sideA, sideB, sideC;
    double calcArea, calcPerimeter;
    char ans;

    do 
    {
        cout << "Enter the lengths of the 3 sides of the triangle: ";
        cin >> sideA >> sideB >> sideC;

        computeTriangle(sideA, sideB, sideC, calcArea, calcPerimeter);

        if (calcArea == 0 && calcPerimeter == 0) 
        {
            cout << "Illegal combinations! Those sides cannot form a triangle.\n";
        } 
        else 
        {
            cout << "Perimeter: " << calcPerimeter << endl;
            cout << "Area: " << calcArea << endl;
        }

        cout << "\nTest again? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

// Function definition
void computeTriangle(double a, double b, double c, double& area, double& perimeter) 
{
    // Check Triangle Inequality Theorem to ensure valid lengths
    if ((a + b > c) && (a + c > b) && (b + c > a) && a > 0 && b > 0 && c > 0) 
    {
        perimeter = a + b + c;
        
        // Calculate semi-perimeter for Heron's formula
        double s = perimeter / 2.0; 
        
        // Calculate area
        area = sqrt(s * (s - a) * (s - b) * (s - c));
    } 
    else 
    {
        // Illegal triangle lengths
        area = 0;
        perimeter = 0;
    }
}