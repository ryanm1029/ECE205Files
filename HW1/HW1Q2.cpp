#include <iostream>
using namespace std;

int main() {
    
    double hours = 0.0;
    int dependents = 0;
    
    // pay and deduction variables
    double grossPay, netPay;
    double socialSecurity, federalTax, stateTax, localTax;
    double unionDues = 20.00;
    double healthIns = 0.0;

    cout << "Please input total hours worked this week:";
    cin >> hours;

    cout << "Please input total number of dependents:";
    cin >> dependents;

    // calculate gross pay
    if (hours > 40.0) {
        // 40 hours at base rate + extra hours at 1.5x rate
        grossPay = (40.0 * 36.75) + ((hours - 40.0) * (36.75 * 1.5));
    } else {
        grossPay = hours * 36.75;
    }

    // calculate deductions
    socialSecurity = grossPay * 0.06;
    federalTax = grossPay * 0.15;
    stateTax = grossPay * 0.04;
    localTax = grossPay * 0.01;
    
    // health insurance logic
    if (dependents >= 2) {
        healthIns = 40.00;
    }

    // calculate Net Pay
    netPay = grossPay - (socialSecurity + federalTax + stateTax + localTax + unionDues + healthIns);

    // output formatting
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    // print results
    cout << "Gross Pay: " << grossPay << endl;
    cout << "Social Security Tax: " << socialSecurity << endl;
    cout << "Federal Income Tax: " << federalTax << endl;
    cout << "State Tax: " << stateTax << endl;
    cout << "Local Tax: " << localTax << endl;
    cout << "Union Dues: " << unionDues << endl;
    cout << "Health Insurance: " << healthIns << endl;
    cout << "Net Take-Home Pay: " << netPay << endl;

    return 0;
}