#include <iostream>

using namespace std;

// Function declarations (Prototypes)
void getInput(int& hours, int& minutes);
void convertTime(int& hours, char& amPm);
void outputTime(int hours, int minutes, char amPm);

int main() 
{
    int hours, minutes;
    char amPm;

    cout << "Time Conversion Program." << endl;
    cout << "Enter a negative hour to quit." << endl;

    do 
    {
        getInput(hours, minutes);
        
        // Exit condition
        if (hours < 0) 
        {
            cout << "Exiting program.\n";
            break;
        }

        convertTime(hours, amPm);
        outputTime(hours, minutes, amPm);

    } while (hours >= 0);

    return 0;
}

// Function definitions
void getInput(int& hours, int& minutes) 
{
    cout << "\nEnter hours and minutes (separated by a space): ";
    cin >> hours;
    if (hours >= 0) 
    {
        cin >> minutes;
    }
}

void convertTime(int& hours, char& amPm) 
{
    if (hours >= 12) 
    {
        amPm = 'P';
        if (hours > 12) 
        {
            hours = hours - 12;
        }
    } 
    else 
    {
        amPm = 'A';
        if (hours == 0) 
        {
            hours = 12;
        }
    }
}

void outputTime(int hours, int minutes, char amPm) 
{
    cout << "12-hour format: " << hours << ":";
    
    // Formatting to ensure minutes display as two digits (e.g., 2:05 instead of 2:5)
    if (minutes < 10) 
    {
        cout << "0";
    }
    cout << minutes << " " << amPm << "M" << endl;
}