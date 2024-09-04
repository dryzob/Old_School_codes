#ifndef LAND_H
#define LAND_H

#include <string>
#include "player.h"

using namespace std;

enum LandTypes {FOREST, LAKE, CAVE, DESERT, MOUNTAIN, JUNGLE, PLAINS, NUM_LANDS};

// game modifiers
const int RECOVERY_AMT = 3;
const int HINT_CHANCE = 35;
const int KEY_CHANCE = 15;
const int DOOR_CHANCE = 60;
    // event modifiers
const int OASIS_CHANCE = 10;
const int BEAR_CHANCE = 25;
const int JON_CHANCE = 45;
const int CRYSTAL_CHANCE = 55;
const int VOLCANO_CHANCE = 20;
const int VOLCANO_DAMAGE = 2;
const int BERRY_CHANCE = 65;
const int BERRY_DAMAGE = 1;

class Land {
    public:
    virtual string getDescription(){
        return "Description of land";
    }
    
    virtual string visit(Player& player){
        return "You visit a land";
    }
};

class Forest : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Lake : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Cave : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Desert : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Mountain : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Jungle : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};
class Plains : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

Land* getRandomLand();

#endif