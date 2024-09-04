#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>

using namespace std;

class Food {
    public:
    Food();
    Food(string name, double energy, double fat, double sugar, double protein, double sodium);
    
    void setName(string name);
    void setEnergy(double energy);
    void setFat(double fat);
    void setSugar(double sugar);
    void setProtein(double protein);
    void setSodium(double sodium);
    string getName();
    double getEnergy();
    double getFat();
    double getSugar();
    double getProtein();
    double getSodium();
    
    //Build addition overide, add together the stats
    Food operator+(Food rhs);

    private:
    string name = "cheese";
    double energy = 0;
    double fat = 0;
    double sugar = 0;
    double protein = 0;
    double sodium = 0;
    
    
};

#endif