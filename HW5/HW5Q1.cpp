#include <iostream>

using namespace std;

class BicycleSpeedometer {
private:
    double distance; // in miles
    double time;     // in minutes

public:
    // Mutators
    void setDistance(double d);
    void setTime(double t);
    
    // Member function to compute average speed
    double computeAverageSpeed();
};

// function definitions

void BicycleSpeedometer::setDistance(double d) {
    distance = d;
}

void BicycleSpeedometer::setTime(double t) {
    time = t;
}

double BicycleSpeedometer::computeAverageSpeed() {
    // Avoid division by zero
    if (time == 0) {
        return 0.0;
    }
    // Speed = distance / time (converted to hours)
    return distance / (time / 60.0);
}

// Main

int main() {
    BicycleSpeedometer bike;
    double dist, time;

    cout << "Enter distance traveled (in miles): ";
    cin >> dist;
    
    cout << "Enter time taken (in minutes): ";
    cin >> time;

    bike.setDistance(dist);
    bike.setTime(time);

    cout << "The average speed is: " << bike.computeAverageSpeed() << " mph" << endl;

    return 0;
}