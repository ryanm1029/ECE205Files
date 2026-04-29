#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    
    cout << "Enter an integer N to find all prime numbers less than N: ";
    cin >> n;

    if (n <= 2) {
        cout << "There are no prime numbers less than " << n << "." << endl;
        return 0;
    }

    // 1. Create a boolean vector of size N, initialized to true.
    // prime[i] will be true if 'i' is prime, and false if 'i' is not prime.
    vector<bool> isPrime(n, true);

    // 0 and 1 are mathematically not prime numbers, so mark them false
    isPrime[0] = false;
    isPrime[1] = false;

    // 2. The Sieve of Eratosthenes Algorithm
    // We only need to check numbers up to the square root of n (p * p < n)
    for (int p = 2; p * p < n; p++) {
        
        // If isPrime[p] is true, then 'p' is a prime number
        if (isPrime[p] == true) {
            
            // Cross out (mark as false) all multiples of 'p'.
            // We start at p*p because any smaller multiple would have 
            // already been crossed out by a smaller prime number.
            for (int i = p * p; i < n; i += p) {
                isPrime[i] = false;
            }
        }
    }

    // 3. Print the results
    cout << "Prime numbers less than " << n << " are:" << endl;
    for (int i = 2; i < n; i++) {
        if (isPrime[i]) {
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}