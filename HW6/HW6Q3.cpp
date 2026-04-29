#include <iostream>
#include <vector>

using namespace std;

int main() {

    int N;

    cout << "Enter an integer N: " << endl;
    cin >> N;

    vector<int> primeCandidates(N, 1);

    //iterate through every valid prime, invalidating every multiple of it up to N
    for (int i = 2; i < N; i++){
        if (primeCandidates[i] == 1) {
            for(int j = i; j * i < N; j++){
                primeCandidates[i*j] = 0;
            }
        }
    }

    //print primes
    cout << "Prime Numbers below " << N << endl;
    for (int i = 2; i < N; i++){
        if (primeCandidates[i] == 1) {
            cout << i << endl;
        }
        
    } 

    return 0;
}