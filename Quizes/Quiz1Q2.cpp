#include <iostream>
using namespace std;

int main() {
    bool inOrder(int i1, int i2, int i3);   

    int i1;
    int i2;
    int i3;

    cout << "Please enter the first integer:" << endl;
    cin >> i1;
    cout << "Please enter the second integer:" << endl;
    cin >> i2;
    cout << "Please enter the third integer:" << endl;
    cin >> i3;
    
    if (inOrder(i1,i2,i3)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}

bool inOrder(int i1, int i2, int i3) {

    if (i1 < i2 && i2 < i3) {
        return true;
    } else {
        return false;
    }
}