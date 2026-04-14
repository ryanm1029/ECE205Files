#include <iostream>

using namespace std;

class PrimeNumber {
private:
    int prime;
    bool isPrime(int n); // Helper function to check if a number is prime

public:
    PrimeNumber();
    PrimeNumber(int p);
    
    int getPrime();
    
    // Operator overloads
    PrimeNumber operator++();      // Prefix ++
    PrimeNumber operator++(int);   // Postfix ++
    PrimeNumber operator--();      // Prefix --
    PrimeNumber operator--(int);   // Postfix --
};

// Function definitions

bool PrimeNumber::isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

PrimeNumber::PrimeNumber() {
    prime = 1; // Requirement specifies default is 1
}

PrimeNumber::PrimeNumber(int p) {
    prime = p;
}

int PrimeNumber::getPrime() {
    return prime;
}

// Prefix ++
PrimeNumber PrimeNumber::operator++() {
    prime++;
    while (!isPrime(prime)) {
        prime++;
    }
    return *this;
}

// Postfix ++
PrimeNumber PrimeNumber::operator++(int) {
    PrimeNumber temp = *this;
    prime++;
    while (!isPrime(prime)) {
        prime++;
    }
    return temp;
}

// Prefix --
PrimeNumber PrimeNumber::operator--() {
    prime--;
    while (!isPrime(prime) && prime > 1) {
        prime--;
    }
    // Floor the number to 1 per the default requirement bounds
    if (prime < 1) prime = 1;
    
    return *this;
}

// Postfix --
PrimeNumber PrimeNumber::operator--(int) {
    PrimeNumber temp = *this;
    prime--;
    while (!isPrime(prime) && prime > 1) {
        prime--;
    }
    if (prime < 1) prime = 1;
    
    return temp;
}

// Main tests

int main() {
    PrimeNumber p(13);
    
    cout << "Initial prime: " << p.getPrime() << endl;

    // Test prefix ++
    PrimeNumber p2 = ++p;
    cout << "After prefix ++, current object is: " << p.getPrime() 
         << " (Returned: " << p2.getPrime() << ")" << endl;

    // Test postfix ++
    PrimeNumber p3 = p++;
    cout << "After postfix ++, current object is: " << p.getPrime() 
         << " (Returned: " << p3.getPrime() << ")" << endl;

    // Test prefix --
    PrimeNumber p4 = --p;
    cout << "After prefix --, current object is: " << p.getPrime() 
         << " (Returned: " << p4.getPrime() << ")" << endl;

    // Test postfix --
    PrimeNumber p5 = p--;
    cout << "After postfix --, current object is: " << p.getPrime() 
         << " (Returned: " << p5.getPrime() << ")" << endl;

    return 0;
}