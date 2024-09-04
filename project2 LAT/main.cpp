/*
    Miles Burkey
    This code only works for numbers 1-20
*/

#include <iostream>
#include <cmath>

using namespace std;

long long Factorial(int num) {
    long long total = 0;
    
    for (int i = num; i > 0; i--) {
        if (total == 0) {
            total = i;
        } else {
            total *= i;
        }
    }
    return total;
}

int main() {
    
    int n = 0; // top counter
    int k = 0; // Grid size and bottom counter of combination
    int evens = 0; // tracks amount of 2's on top
    long long top = 0; // value of top of the combination
    long long bottom = 0; // value of bottom of the combination
    long long r = 0; // final answer of combination
    
    
    // Input section
    cout << "\n\tPlease select grid size between 1 and 20: ";
    cin >> n;
    cout << endl;
    
    if ((n < 1) || (n > 20)) {
        cout << "\tERROR: OUT OF BOUNDS\n" << endl;
        return 1;
    }
    
    k = n * 2; // top counter is double the grid size

    // Calculating top
    for (int i = k; i > n; i--) {
        //check if even to replace with 2
        if (i%2 == 0) {
            if (top == 0) { // initial even case
                top = 2;
                evens++;
            } else {
                top *= 2;
                evens++;
            }
        } else {
            if (top == 0) { // initial odd case
                top = i;
            } else {
                top *= i;
            }
        }
    }
    
    bottom = Factorial(n - evens);
    
    r = top / bottom;
    
    cout << "\tNumber of paths: | " << r << " |\n\n" << endl;
    
    return 0;
}