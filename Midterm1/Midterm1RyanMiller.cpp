#include <iostream>

using namespace std;

void calculateTime(int rawTime, int& hours, int& minutes, char& period);

int main() {

    int startTime = 0;
    int startHours, startMinutes;
    char startPeriod;

    int endTime = 0;
    int endHours, endMinutes;
    char endPeriod;
    
    int tempTime = 0;
    while (1) {
        cout << "Start time in 24-hour format = ";
        cin >> tempTime;
        if (tempTime % 100 < 60 && ((tempTime - (tempTime % 100)) / 100) < 24 && tempTime != 2359) {
            startTime = tempTime;
            break;
        } else {
            cout << "Invalid time!" << endl;
        }
    }
    
    calculateTime(startTime, startHours, startMinutes, startPeriod);

    while (1) {
        cout << "End time in 24-hour format = ";
        cin >> tempTime;
        if (tempTime % 100 < 60 && ((tempTime - (tempTime % 100)) / 100) < 24 && tempTime > startTime) {
            endTime = tempTime;
            break;
        } else {
            cout << "Invalid time!" << endl;
        }
    }

    cout << endl;

    calculateTime(endTime, endHours, endMinutes, endPeriod);
    int diff = (endHours * 60 + endMinutes) - (startHours * 60 + startMinutes);
    
    if (startHours == 0) {
        startHours = 12;
    } 
    if (startHours > 12) {
        startHours -= 12;
    } 

    if (endHours == 0) {
        endHours = 12;
    } 
    if (endHours > 12) {
        endHours -= 12;
    } 

    if (startMinutes < 10) {
        cout << "Start time in 12-hour format = " << startHours << ":0" <<  startMinutes << " " << startPeriod << "M" << endl;
    } else {
        cout << "Start time in 12-hour format = " << startHours << ":" <<  startMinutes << " " << startPeriod << "M" << endl;

    }
    if (endMinutes < 10) {
        cout << "End time in 12-hour format = " << endHours << ":0" << endMinutes << " " << endPeriod << "M" << endl;
    } else {
        cout << "End time in 12-hour format = " << endHours << ":" << endMinutes << " " << endPeriod << "M" << endl;

    }

    cout << "Difference in minutes = " << diff << " minutes";
    return 0;
}

void calculateTime(int rawTime, int& hours, int& minutes, char& period) {
    minutes = rawTime % 100;
    hours = (rawTime - minutes) / 100;
    if (hours >= 12) {
        period = 'P';
    } else {
        period = 'A';
    }
}