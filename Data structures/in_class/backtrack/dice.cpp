#include <iostream>
#include <vector>

using namespace std;

ostream& operator<<(ostream os, vector<int> vec) {
    for(auto ele : vec) {
        os << ele << " ";
    }
    return os;
}

void diceRollsHelper(int dice, vector<int>& chosen);

void diceRolls(int dice) {
    vector<int> chosen;
    diceRollsHelper(dice, chosen);
}

void diceRollsHelper(int dice, vector<int>& chosen) {
    if (dice == 0) {
        cout << chosen << endl;
    } else {
        for(int i = 1; i <= 6; i++) {
            chosen.push_back(i);
            diceRollsHelper(dice - 1, chosen);
            chosen.pop_back();
        }
    }
}

int main() {
    diceRolls(2);

    return 0;
}