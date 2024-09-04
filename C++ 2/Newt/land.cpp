#include<iostream>
#include "land.h"

using namespace std;

Land* getRandomLand() {
    LandTypes selection = (LandTypes)(rand() % NUM_LANDS);
    switch(selection) {
        case FOREST:
            return new Forest;
            break;
        case LAKE:
            return new Lake;
            break;
        case CAVE:
            return new Cave;
            break;
        case MOUNTAIN:
            return new Mountain;
            break;
        case DESERT:
            return new Desert;
            break;
        case JUNGLE:
            return new Jungle;
            break;
        case PLAINS:
            return new Plains;
            break;
        default:
            return nullptr;
    }
}

// Forest
string Forest::getDescription() {
    return "a dark and dense forest\n";
}
string Forest::visit(Player& player) {
    int chance = (rand() % 100) + 1;
    
    if ((chance < BEAR_CHANCE) && (!player.hasKeyPiece3())) {
        Enemy bear(BEAR_HEALTH);
        bear.bearFight(player, bear);
        return " "; // Buffer output
    } else {
        player.setHunger(RECOVERY_AMT);
        return "\nYou find some berries and eat them.\n";
    }
}

// Lake
string Lake::getDescription() {
    return "a large clear lake, briming with fish.\n";
}
string Lake::visit(Player& player) {
    if (player.hasFishRod()) {
        cout << "\nYou use the fishing rod to catch some fish.";
        player.setHunger(RECOVERY_AMT);
    }
    player.setThirst(RECOVERY_AMT);
    return "\nYou drink from the lake, re-hydrating yourself.\n";
}

// Caves
string Cave::getDescription() {
    return "a dark opening residing in the side of the hill.\n";
}
string Cave::visit(Player& player) {
    int chance = (rand() % 100) + 1;
    
    if (player.hasCrystal() || player.getJonQuest()) {
        player.setHunger(RECOVERY_AMT);
        return "\nYou find some tasty mushrooms!\n";
    } else if (chance < CRYSTAL_CHANCE) {
        player.gainCrystal(true);
        return "\nYou stumble upon a shiny crystal!\n";
    } else {
        return "\nA swarm of bats scare you out of the cave.\n";
    }
}

// Desert
string Desert::getDescription() {
    return "rolling hills of golden sand as far as the horizon.\n";
}
string Desert::visit(Player& player) {
    int chance = (rand() % 100) + 1;
    
    if (chance < OASIS_CHANCE) {
        player.setThirst(MAX_THIRST);
        player.setHunger(MAX_HUNGER);
        player.setHealth(MAX_HEALTH);
        if (!(player.hasKeyPiece2())) {
            cout << "\nYou find a piece of a key half buried in the sand";
            player.gainKeyPiece2(true);
        }
        return "\nYou find a lone sparkling pool of water surrounded in vegetation\n";
    } else {
        player.nextTurn();
        return "\nYou wander, unaware of the time that has passed.\n";
    }
}

// Mountain
string Mountain::getDescription() {
    return "a mountain towering over you.\n";
}
string Mountain::visit(Player& player) {
    int chance = (rand() % 100) + 1;
    
    if (chance < VOLCANO_CHANCE) {
        player.takeDamage(VOLCANO_DAMAGE);
        return "\nThe mountain roars as lava flows toward you!\n";
    } else if (chance < HINT_CHANCE) {
        return "\nOn top of the mountain, you can see a small glimmer coming from a far off desert.\n";
    } else if (chance < DOOR_CHANCE) {
        cout << "\nAmong the various crevices you find a grand door, the center of which is a large lock." << endl;
        if (player.hasKeyPiece1() && player.hasKeyPiece2() && player.hasKeyPiece3()) {
            player.finishGame(true);
            return "\nYou approach the large door\n\n";
        } else {
            return "\n\n";
        }
    } else {
        player.setHealth(player.getHealth() + RECOVERY_AMT);
        return "\nStanding high over the lands you feel a sense of courage.\n";
    }
}

// Jungle
string Jungle::getDescription() {
    return "a lush, green jungle beaming with life.\n";
}
string Jungle::visit(Player& player) {
    string userInput;
    int userNum = 0;
    int chance = (rand() % 100) + 1;
    
    if ((chance < KEY_CHANCE) && !(player.hasKeyPiece1())) {
        cout << "\nYou find a deteriorating pyramid.\nInside holds what seems like a key piece.";
        player.gainKeyPiece1(true);
    }
    
    if (chance < BERRY_CHANCE) {
        cout << "\nYou find two berry bushes.\nDo you choose 1 or 2?\n";
        cin >> userInput;
        userNum = atoi(userInput.c_str());
        if (userNum == 1) {
            player.takeDamage(BERRY_DAMAGE);
            return "\nThat berry didn't taste right\n";
        } else if (userNum == 2) {
            player.setHunger(RECOVERY_AMT);
            return "\nDelicious!\n";
        }
    } else {
        return "\nYou walk through the dark underbrush.\n";
    }
}

// Plains
string Plains::getDescription() {
    return "fields of tall grasses.\n";
}
string Plains::visit(Player& player) {
    int chance = (rand() % 100) + 1;
    
    
    if (chance < JON_CHANCE) {
        cout << "\nYou see a giant sitting in the field, a sign near him has a crystal drawn on it." << endl;
        
        if (player.getJonQuest()) {
            return "You two exchange waves as you pass by.\n";
        } else if (player.hasCrystal()) {
            player.gainCrystal(false);
            player.gainFishRod(true);
            player.finishJonQuest(true);
            player.questComplete("Jon's crystal");
            return "You hand the crystal to the giant, he silently hands you an item.\n";
        } else { 
            return "You leave him alone.\n";
        }
    } else {
        return "\nYou pass through the fields in the warm sunshine.\n";
    }
}