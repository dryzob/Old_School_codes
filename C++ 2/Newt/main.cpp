#include <iostream>
#include <iomanip>
#include <time.h>
#include "player.h"
#include "land.h"

using namespace std;

const int FORMAT_NUM = 90;
const int WORLD_SIZE = 4;

Land* world[WORLD_SIZE][WORLD_SIZE];

void buildWorld() {
    for (int i = 0; i < WORLD_SIZE; i++) {
        for (int j = 0; j < WORLD_SIZE; j++) {
            world[i][j] = getRandomLand();
        }
    }
}

int main() {
    srand(time(0));
    string userInput;
    int userNum = 0;
    
    buildWorld();
    
    Player jack(WORLD_SIZE / 2, WORLD_SIZE / 2);
    
    cout << "\n\nYou wake up alone in a unknown land." << endl;
    cout << "Looking around, you see " << world[jack.getXPos()][jack.getYPos()]->getDescription()<< endl;
    
    while(jack.isAlive()) {
        
        jack.nextTurn();
        cout << jack.toString() << endl;
    
        cout << "To the NORTH you see " << world[jack.getXPos()][(jack.getYPos() + 1) % WORLD_SIZE]->getDescription() << endl;
        
        int xTemp = (jack.getXPos() - 1) < 0 ? WORLD_SIZE - 1 : (jack.getXPos() - 1);
            cout << "To the EAST you see " << world[xTemp][jack.getYPos()]->getDescription() << endl;
        
        cout << "To the WEST you see " << world[(jack.getXPos() + 1) % WORLD_SIZE][jack.getYPos()]->getDescription() << endl;
        
        int yTemp = (jack.getYPos() - 1) < 0 ? WORLD_SIZE - 1 : (jack.getYPos() - 1);
            cout << "To the SOUTH you see " << world[jack.getXPos()][yTemp]->getDescription() << endl;
        
        cout << "Where do you wish to go?" << endl;
        cout << "1: North, 2: East, 3: West, 4: South, 5: Look around" << endl;
        
        cin >> userInput;
        userNum = atoi(userInput.c_str());
        cout << setfill('-') << setw(FORMAT_NUM) << "-" << setfill(' ') << endl;
        
        jack.movement(userNum);
        jack.checkBounds(jack.getXPos(), jack.getYPos(), WORLD_SIZE);
        
        cout << "|| X position: " << jack.getXPos() << " | Y position: " << jack.getYPos() << " ||" << endl;
        cout << setfill('_') << setw(FORMAT_NUM) << "_" << setfill(' ') << endl;
        cout << world[jack.getXPos()][jack.getYPos()]->visit(jack);
        cout << setfill('_') << setw(FORMAT_NUM) << "_" << setfill(' ') << endl << endl;
        
        
        if (jack.getEnding()) {
            jack.EndingSeq();
            break;
        }
    }
    
    if (!(jack.isAlive())) {
        cout << "\nYOU DIED" << endl;
        cout << "Score: " << jack.getScore() << "\n\n\n" <<endl;
    }
    
    return 0;
}