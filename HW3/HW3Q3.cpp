#include <iostream>

using namespace std;

// Function declaration
int calculateMinutes(int startTime, int endTime);

int main() 
{
    int start, end;
    char ans;

    do 
    {
        cout << "Enter start time and end time in military format (e.g. 2300 0600): ";
        cin >> start >> end;

        int totalMinutes = calculateMinutes(start, end);
        cout << "Minutes between times: " << totalMinutes << " minutes." << endl;

        cout << "\nCalculate another interval? (y/n): ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}

// Function definition
int calculateMinutes(int startTime, int endTime) 
{
    // Extract hours and minutes using division and modulo
    int startHours = startTime / 100;
    int startMins = startTime % 100;
    
    int endHours = endTime / 100;
    int endMins = endTime % 100;

    // Convert both times strictly into minutes since midnight
    int absoluteStartMins = (startHours * 60) + startMins;
    int absoluteEndMins = (endHours * 60) + endMins;

    int difference = absoluteEndMins - absoluteStartMins;

    // If difference is negative, the end time is on the following day
    if (difference < 0) 
    {
        // Add 24 hours worth of minutes
        difference = difference + (24 * 60);
    }

    return difference;
}