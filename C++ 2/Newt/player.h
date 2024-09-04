#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

enum Directions {BUFFFER, NORTH, EAST, WEST, SOUTH};

const int FORMAT_NUMQ = 33;
// player consts
const int MAX_HEALTH = 20;
const int MAX_HUNGER = 20;
const int MAX_THIRST = 10;
const int PLAYER_DAMAGE = 2;
const int PLAYER_DODGE = 25;
// Bear consts
const int BEAR_HEALTH = 12;
const int BEAR_ATTACKS[3] = {2, 15, 50};
const int BEAR_DAMAGE = 1;

class Quests {
    public:
    void questComplete(string s1);
    void finishJonQuest(bool q);
    bool getJonQuest();
    void finishGame(bool g);
    bool getEnding();
    void EndingSeq();
    
    protected:
    bool jonQ;
    bool finish;
};

class Items {
  public:
  void gainCrystal(bool c);
  bool hasCrystal() const;
  void gainFishRod(bool f);
  bool hasFishRod() const;
  
  // Keys
  void gainKeyPiece1(bool k1);
  bool hasKeyPiece1() const;
  void gainKeyPiece2(bool k2);
  bool hasKeyPiece2() const;
  void gainKeyPiece3(bool k3);
  bool hasKeyPiece3() const;
  
  protected:
  bool crystal;
  bool fishingRod;
  bool keyPiece1;
  bool keyPiece2;
  bool keyPiece3;
};

class Player : public Quests, public Items {
    public:
    Player(int H);
    Player(int initX, int initY);
    
    // stats
    int getHealth() const;
    int getHunger() const;
    int getThirst() const;
    int getXPos() const;
    int getYPos() const;
    int getScore() const;
    
    void setHealth(int x);
    void setHunger(int x);
    void setThirst(int x);
    void setScore(int x);
    void setPos(int newX, int newY);
    void takeDamage(int dmg);
    
    // others
    string toString();
    void nextTurn();
    bool isAlive();
    void movement(int dir);
    void checkBounds(int x, int y, int size);
    
    private:
    // stats
    int thirst;
    int hunger;
    int health;
    int score;
    // position
    int x, y;
};

class Enemy : public Player {
    public:
    Enemy(int h);
    void bearFight(Player& player, Enemy& bear);
    
    private:
    int health;
};




#endif