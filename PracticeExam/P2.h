#pragma once
#include <string>

namespace Factory {
    class Robot {
    public: 
        Robot(std::string n, double b);
        virtual void operate();
    protected:
        std::string name;
        double batteryLevel;
        static int totalRobots;
    };

    class WelderBot : public Robot {
    public:        
        WelderBot(std::string n, double b, int w);
        
        friend std::ostream& operator<<(std::ostream& out, const WelderBot w);

        void operate() override;

        WelderBot operator+(WelderBot botB);

    private:
        int weldingTemperature;
    };
}