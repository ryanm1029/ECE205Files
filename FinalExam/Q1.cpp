#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double re;
    double im;
public:
    //Constructors
    Complex();
    Complex(double r);
    Complex(double r, double i);
    
    //Operations
    double calculateMagnitude(Complex a);
    Complex addComplex(Complex a, Complex b);
    Complex subComplex(Complex a, Complex b);
    Complex multComplex(Complex a, Complex b);
    Complex divComplex(Complex a, Complex b);

    friend ostream& operator<<(ostream& out, const Complex a);


};

int main(){

    Complex a = Complex();
    Complex b = Complex();


    while(1){
        int choice;
        double tempRe;
        double tempIm;

        cout << "Select from the following choices:" << endl;
        cout << "1: Edit Complex number A" << endl;
        cout << "2: Edit Complex number B" << endl;
        cout << "3: Calculate magnitude of A" << endl;
        cout << "4: Calculate magnitude of B" << endl;
        cout << "5: Add A and B" << endl;
        cout << "6: Subtract A and B" << endl;
        cout << "7: Multiply A and B" << endl;
        cout << "8: Divide A and B" << endl;
        cout << "9: quit" << endl;
        cin >> choice;



        switch (choice) {
            case 1:
                cout << "Enter real part of A" << endl;
                cin >> tempRe;
                cout << "Enter imaginary part of A" << endl;
                cin >> tempIm;
                a = Complex(tempRe, tempIm);
                break;
            case 2:
                cout << "Enter real part of B" << endl;
                cin >> tempRe;
                cout << "Enter imaginary part of B" << endl;
                cin >> tempIm;
                b = Complex(tempRe, tempIm);
                break;
            case 3:
                cout << a.calculateMagnitude(a) << endl;
                break;
            case 4:
                cout << b.calculateMagnitude(b) << endl;
                break;
            case 5:
                cout << a.addComplex(a, b) << endl;
                break;
            case 6:
                cout << a.subComplex(a, b) << endl;
                break;
            case 7:
                cout << a.multComplex(a, b) << endl;
                break;
            case 8:
                cout << a.divComplex(a, b) << endl;
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }


    }
    return 0;
}

//Constructor Definitions
Complex::Complex() {
    re = 0;
    im = 0;
}
Complex::Complex(double r){
    re = r;
    im = 0;
}
Complex::Complex(double r, double i){
    re = r;
    im = i;
}

//Operation definitions
double Complex::calculateMagnitude(Complex a){
    return sqrt((a.re * a.re) + (a.im * a.im));
}
Complex Complex::addComplex(Complex a, Complex b){
    return Complex(a.re + b.re,a.im+b.im);
}
Complex Complex::subComplex(Complex a, Complex b){
    return Complex(a.re - b.re,a.im - b.im);
}
Complex Complex::multComplex(Complex a, Complex b){
    double real = a.re * b.re - a.im * b.im;
    double imag = a.re * b.im + a.im * b.re;
    return Complex(real, imag);
}
Complex Complex::divComplex(Complex a, Complex b){
    double aa = a.re;
    double bb = a.im;
    double cc = b.re;
    double dd = b.im;
    double real = (aa*cc+bb*dd)/(cc*cc+dd*dd);
    double imag = (bb*cc-aa*dd)/(cc*cc+dd*dd);
    return Complex(real, imag);
}

ostream& operator<<(std::ostream& out,  const Complex a) {
    out << "Real Component: " << a.re << " | Imaginary Component: " << a.im << endl;
    return out;
}