#include "food.h"

Food::Food() {
    name = "cheese";
    energy = 0;
    fat = 0;
    sugar = 0;
    protein = 0;
    sodium = 0;
}

Food::Food(string name, double energy, double fat, double sugar, double protein, double sodium) {
    this -> name = name;
    this -> energy = energy;
    this -> fat = fat;
    this -> sugar = sugar;
    this -> protein = protein;
    this -> sodium = sodium;
}
void Food::setName(string name) {
    this -> name = name;
}
void Food::setEnergy(double energy) {
    if (energy < 0) {
        this -> energy = 0;
    }
    else {
        this -> energy = energy;
    }
}
void Food::setFat(double fat) {
    if (fat < 0) {
        this -> fat = 0;
    }
    else {
        this -> fat = fat;
    }
}
void Food::setSugar(double sugar) {
    if (sugar < 0) {
        this -> sugar = 0;
    }
    else {
        this -> sugar = sugar;
    }
}
void Food::setProtein(double protein) {
    if (protein < 0) {
        this -> protein = 0;
    }
    else {
        this -> protein = protein;
    }
}
void Food::setSodium(double sodium) {
    if (sodium < 0) {
        this -> sodium = 0;
    }
    else {
        this -> sodium = sodium;
    }
}

string Food::getName() {
    return name;
}
double Food::getEnergy() {
    return energy;
}
double Food::getFat() {
    return fat;
}
double Food::getSugar() {
    return sugar;
}
double Food::getProtein() {
    return protein;
}
double Food::getSodium() {
    return sodium;
}

Food Food::operator+(Food rhs) {
    Food stat;
    
    stat.energy = energy + rhs.energy;
    stat.fat = fat + rhs.fat;
    stat.sugar = sugar + rhs.sugar;
    stat.protein = protein + rhs.protein;
    stat.sodium = sodium + rhs.sodium;
    
    return stat;
}