#include <iostream>
#include <cmath>

using namespace std;

int partitions(int n);

int numPartitions = 0;

int main() {
    
    int userInput = 0;
    
    cout << "Input number of coins: ";
    cin >> userInput;
    
    numPartitions = partitions(userInput);
    
    cout << "Number of piles: p(" << userInput << ") = " << numPartitions << endl;
    
    return 0;
}

int partitions(int n) {
    
    if (n < 0) {
        return 0;
    } else if (n == 0) {
        return 1;
    } else {
        return (partitions(n - 1) + partitions(n - 2) - partitions(n - 5) - partitions(n - 7));
    }
    
}