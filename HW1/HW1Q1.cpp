#include <iostream>
using namespace std;

int main() {
    
    int seconds;
    int minutes;
    int hours;
    double realHours;
    double realMinutes;

    // initial seconds input
    cout << "Please enter some number of seconds:";
    cin >> seconds;
    
    // calculations
    hours = seconds / 3600;
    minutes = (seconds / 60) % 60;
    realHours = (double)seconds / 3600.0;
    realMinutes = ((double)seconds / 60.0);

    // print hours, remainder mins and remainder seconds
    cout << hours << " Hours, " << minutes << " Minutes and " << seconds % 60 << " Seconds" << endl;
    
    // set precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    // print exact hours and exact mins
    cout << realHours << " Hours and " << realMinutes << " Minutes" << endl;

    return 0;
}