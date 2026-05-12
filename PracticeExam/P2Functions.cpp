#include "P2.h"
#include <iostream>


namespace Factory {
    
    int Robot::totalRobots = 0;

    Robot::Robot(std::string n, double b){
        name = n;
        batteryLevel = b;
        totalRobots++;
    }

    void Robot::operate(){
        std::cout << "Robot is performing genertic task" << std::endl;
    }

    void WelderBot::operate(){
        std::cout << "WelderBot is welding at " << weldingTemperature << " degrees." << std::endl;
    }

    WelderBot::WelderBot(std::string n, double b, int w) : Robot(n,b) {
        weldingTemperature = w;
    }

    WelderBot WelderBot::operator+(WelderBot botB){
        double newBattery = batteryLevel + botB.batteryLevel;
        if (newBattery > 100) {
            newBattery = 100;
        }
        double newTemp = (weldingTemperature + botB.weldingTemperature)/2;
        return WelderBot("NewBot", newBattery, newTemp);
    }

    std::ostream& operator<<(std::ostream& out,  const WelderBot w) {
        out << "Welder: " << w.name << " | Temp: " << w.weldingTemperature << " | Battery Level: " << w.batteryLevel << std::endl;
        return out;
    } 

}
