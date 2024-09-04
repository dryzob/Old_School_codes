#include "player.h"

Player::Player(int H) {
    health = H;
    thirst = 0;
    hunger = 0;
    x = 0;
    y = 0;
    score = 0;
}

Player::Player(int initX, int initY) {
    // stats
    health = MAX_HEALTH;
    thirst = MAX_THIRST;
    hunger = MAX_HUNGER;
    x = initX;
    y = initY;
    score = 0;
    // inventory
    crystal = false;
    fishingRod = false;
    keyPiece1 = false;
    keyPiece2 = false;
    keyPiece3 = false;
    // quest trackers
    jonQ = false;
    finish = false;
    
}

// GETS
int Player::getHealth() const {
    return health;
}
int Player::getHunger() const {
    return hunger;
}
int Player::getThirst() const {
    return thirst;
}
int Player::getXPos() const{
    return x;
}
int Player::getYPos() const {
    return y;
}

int Player::getScore() const {
    return score;
}

// SETS
void Player::setHealth(int h) {
    health += h;
    if (health > MAX_HEALTH) {
        health = MAX_HEALTH;
    }
}
void Player::setHunger(int u) {
    hunger += u;
    if (hunger > MAX_HUNGER) {
        hunger = MAX_HUNGER;
    }
}
void Player::setThirst(int t) {
    thirst += t;
    if (thirst > MAX_THIRST) {
        thirst = MAX_THIRST;
    }
}
void Player::setScore(int s) {
    score += s;
}
void Player::setPos(int PosX, int PosY) {
    x = PosX;
    y = PosY;
}

string Player::toString() {
    stringstream ss;
    ss << "~~~~~~~~~~~~~" << endl;
    ss << "Health: " << health << endl;
    ss << "Hunger: " << hunger << endl;
    ss << "Thirst: " << thirst << endl;
    ss << "Key Items:" << endl;
    if (crystal) {
        ss << "Crystal" << endl;
    }
    if (fishingRod) {
        ss << "Fishing Rod" << endl;
    }
    if (keyPiece1) {
        ss << "Key piece 1" << endl;
    }
    if (keyPiece2) {
        ss << "Key piece 2" << endl;
    }
    if (keyPiece3) {
        ss << "Key piece 3" << endl;
    }
    ss << "~~~~~~~~~~~~~" << endl;
    
    return ss.str();
}

void Player::nextTurn() {
    hunger--;
    thirst--;
    score++;
    
    if (hunger <= 0) {
        hunger = 0;
        health--;
    }
    if (thirst <= 0) {
        thirst = 0;
        health--;
    }
}

bool Player::isAlive() {
    return health > 0;
}

void Player::movement(int dir) {
    cout << endl << endl;
    switch (dir) {
            case NORTH:
                cout << "You moved North" << endl;
                setPos(getXPos(), getYPos()+1);
            break;
            case EAST:
                cout << "You moved East" << endl;
                setPos(getXPos()-1, getYPos());
            break;
            case WEST:
                cout << "You moved West" << endl;
                setPos(getXPos()+1, getYPos());
            break;
            case SOUTH:
                cout << "You moved South" << endl;
                setPos(getXPos(), getYPos()-1);
            break;
            default: // invalid commands
            cout << "You stayed where you were" << endl;
        }
}

void Player::checkBounds(int x, int y, int size) {
    if (x >= size) {
        setPos(0, y);
    }
    if (y >= size) {
        setPos(x, 0);
    }
    if (x < 0) {
        setPos((size - 1), y);
    }
    if (y < 0) {
        setPos(x, (size - 1));
    }
}

void Player::takeDamage(int dmg) {
    health -= dmg;
}

// ITEMS CLASS
void Items::gainCrystal(bool c) {
    crystal = c;
}
bool Items::hasCrystal() const {
    return crystal;
}
void Items::gainFishRod(bool f) {
    fishingRod = f;
}
bool Items::hasFishRod() const {
    return fishingRod;
}
void Items::gainKeyPiece1(bool k1) {
    keyPiece1 = k1;
}
bool Items::hasKeyPiece1() const {
    return keyPiece1;
}
void Items::gainKeyPiece2(bool k2) {
    keyPiece2 = k2;
}
bool Items::hasKeyPiece2() const {
    return keyPiece2;
}
void Items::gainKeyPiece3(bool k3) {
    keyPiece3 = k3;
}
bool Items::hasKeyPiece3() const {
    return keyPiece3;
}

// QUEST CLASS
void Quests::finishJonQuest(bool q) {
    jonQ = q;
}
bool Quests::getJonQuest() {
    return jonQ;
}

void Quests::questComplete(string s1) {
    cout << "\t\t" << setfill('-') << setw(FORMAT_NUMQ) << "-" << setfill(' ') << endl;
    cout << "\t\t|\tQuest Complete!\t\t|" << endl;
    cout << "\t\t|\t " << s1 << "\t\t|" << endl;
    cout << "\t\t" << setfill('-') << setw(FORMAT_NUMQ) << "-" << setfill(' ') << endl;
}

void Quests::finishGame(bool g) {
    finish = g;
}

bool Quests::getEnding() {
    return finish;
}

void Quests::EndingSeq() {
    string userInput;
    cout << "\nThe three parts of the key float from your hands and forms the complete key." << endl;
    cout << "You slide the key into the lock and the door rumbles and creaks open" << endl;
    cout << "At the center of this large dusty room is a white cake with lit candles on the top." << endl;
    cout << "\n\t\t\tDo you accept the cake?" << endl;
    cout << "\n\t\t\t   Y/N: ";
    cin >> userInput;
    cout << endl;
    
    if ((userInput == "Y") || (userInput == "y") || (userInput == "yes") || (userInput == "Yes")) {
        cout << "\n\n\n\n\n\n\n\t\t\tIt is delicous\n\n\n\n\n\n\n\n\n\n" << endl;
    } else {
        cout << "\n\n\n\n\n\n\n\t\t\tAll goes dark\n\n\n\n\n\n\n\n\n\n" << endl;
    }
}

// Emeny class
Enemy::Enemy(int h) : Player(h) {}

void Enemy::bearFight(Player& player, Enemy& bear) {
    int bearChance;
    int playerChance;
    string userInput;
    int userNum = 0;
    bool isDefend = false;
    
    cout << "A large brown bear takes you by surprise!" << endl;
    while (player.isAlive() && bear.isAlive()) {
        bearChance = (rand() % 100) + 1;
        playerChance = (rand() % 100) + 1;
        
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        cout << "Your Health: " << player.getHealth() << " / " << MAX_HEALTH << endl;
        cout << "Bear Health: " << bear.getHealth() << " / " << BEAR_HEALTH << endl;
        cout << "~~~~~~~~~~~~~~~~~~~~~~~" << endl;
        
        cout << "What do you do?" << endl;
        cout << "1. Strike the bear" << endl;
        cout << "2. Defend" << endl;
        cout << "3. Run" << endl;
        cout << "Choose!: "; 
        cin >> userInput;
        cout << endl;
        userNum = atoi(userInput.c_str());
        
        switch (userNum) { // Player actions
            case 1:
                bear.setHealth(-PLAYER_DAMAGE);
                cout << "You strike at the bear!\n" << endl;
                break;
            case 2:
                isDefend = true;
                cout << "You prepare yourself for the next attack.\n" << endl;
                break;
            case 3:
                if (playerChance < 15) {
                    cout << "You managed to slip away into the forest.\n" << endl;
                    return;
                } else {
                    cout << "The beast manages to keep up!\n" << endl;
                }
                break;
            default:
                cout << "You freeze, unable to act." << endl;
        }
        // Bear Actions
        /*
        TODO: GET RID OF MAGIC NUMBERS
        */
        if (bearChance < BEAR_ATTACKS[0]) {
            cout << "The bear stampers off into the forest\n" << endl;
            return;
        } else if (bearChance < BEAR_ATTACKS[1]) {
            cout << "The bear knashes its teeth." << endl;
            if (isDefend || playerChance < PLAYER_DODGE) {
                cout << "You jump to the side, avoiding the hit!\n" << endl;
            } else {
                player.setHealth(-(BEAR_DAMAGE*3));
                cout << "Its maw tears a chunk from you!" << endl;
            }
        } else if (bearChance < BEAR_ATTACKS[2]) {
            cout << "The bear stands on it's hind legs and roars.\n" << endl; 
        } else {
            cout << "The bear lashes out with its claws." << endl;
            if (isDefend || playerChance < PLAYER_DODGE) {
                cout << "You jump back, avoiding the hit!\n" << endl;
            } else {
                player.setHealth(-BEAR_DAMAGE);
                cout << "The claws land!" << endl;
            }
        }
    }
    if (!bear.isAlive()) {
        cout << "\nThe large mass of fur falls over, a small key piece falls from its jaw\n" << endl;
        player.gainKeyPiece3(true);
        player.questComplete("Bear Fight!");
        return;
    } else if (!player.isAlive()) {
        cout << "\nYour strength leaves you and the world fades to black.\n" << endl;
        return;
    }
}