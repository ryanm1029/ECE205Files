#include <iostream>
using namespace std;

int main() {
    
    int input;

    while(1){
        cout << "Please enter an integer." << endl;
        cin >> input;

        if (input > 0) {
            cout << "Integer is positive" << endl;
        } else {
            cout << "Integer is negative" << endl;
        }
    }
    
    return 0;
}