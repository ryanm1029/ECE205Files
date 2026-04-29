#include <iostream>
using namespace std;

// Recursion requires TWO things:
// 1. A Base Case (When to STOP)
// 2. A Recursive Step (Calling itself with a smaller piece of the puzzle)

// Example 1: Classic Factorial (5! = 5 * 4 * 3 * 2 * 1)
int factorial(int n) {
    // 1. Base Case: If n is 1 or 0, stop and return 1.
    if (n <= 1) {
        return 1;
    }
    // 2. Recursive Step: n * factorial of the number below it
    return n * factorial(n - 1);
}

// Example 2: Recursive Array Sum (Very testable algorithm problem)
// Adds up all numbers in an array.
int sumArray(int arr[], int size) {
    // 1. Base Case: If the array size is 0, the sum is 0.
    if (size == 0) {
        return 0;
    }
    // 2. Recursive Step: Take the last element (arr[size-1]) 
    // and add it to the sum of the REST of the array.
    return arr[size - 1] + sumArray(arr, size - 1);
}

int main() {
    cout << "Factorial of 5: " << factorial(5) << endl;

    int myArr[] = {2, 4, 6, 8, 10};
    // Pass the array and its size (5)
    cout << "Sum of Array: " << sumArray(myArr, 5) << endl;

    return 0;
}