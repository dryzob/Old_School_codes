/*
MADE BY Miles Burkey
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int userNum = 0;
    int currNum = 0;
    int lastNum = 0;
    int length = 1;
    vector<int> sequence;
    
    // Takes input after prompt
    cout << "\n\n\tEnter starting number: ";
    cin >> userNum;
    
    // Set input to current and last number to allow for intial case
    currNum = userNum;
    lastNum = currNum;
    sequence.push_back(userNum);
    
    // Repeat the sequence until 1
    while (currNum != 1) {
        
        // Even check
        if ((currNum%2) == 0) {
            currNum = lastNum / 2;
        }
        else { // Odd
            currNum = (3 * lastNum) + 1;
        }
        
        //Push back current value to vector for displaying the sequence
        sequence.push_back(currNum);
        
        // Set last to current to enable recursive formula
        lastNum = currNum;
        length++;
        
    }
    
    cout << "\n\n\tSequence: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence.at(i) << " ";
    }
    cout << "\n\tLength of sequence: " << length << "\n\n\n";
    
    return 0;
}