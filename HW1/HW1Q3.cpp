#include <iostream>
using namespace std;

int main() {

    double balance = 1000.0;
    double principal = 0;
    double interest = 0;
    double totalInterest = 0;
    double totalPaid = 0;
    double monthlyPayment = 50.0;
    int month = 1;

    // Formatting setup
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::right); //right alignment

    // Print Headers with specific widths
    cout.width(10); cout << "Month";
    cout.width(12); cout << "Interest";
    cout.width(12); cout << "Principal";
    cout.width(12); cout << "Balance";
    cout.width(16); cout << "Total Interest";
    cout.width(12); cout << "Total Paid" << endl;

    // main loop
    while (balance > 0) {
        
        // check if remaining balance plus interest is less than 50 dollars, adjust payment accordingly
        if ((balance * 1.015) < 50.0) {
            monthlyPayment = balance * 1.015;
        }

        interest = balance * 0.015;
        principal = monthlyPayment - interest;
        balance = balance - principal;
        
        totalInterest += interest;
        totalPaid += monthlyPayment;

        

        // Print Row
        cout.width(10); cout << month;
        cout.width(12); cout << interest;
        cout.width(12); cout << principal;
        cout.width(12); cout << balance;
        cout.width(16); cout << totalInterest;
        cout.width(12); cout << totalPaid << endl;

        month++;
    }

    return 0;
}