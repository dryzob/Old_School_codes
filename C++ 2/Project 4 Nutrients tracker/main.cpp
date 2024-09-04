#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "food.h"

using namespace std;

vector<Food> menu;
void MakeMenu();
void NewItem();

int main() {
    vector<Food> meal; // will hold the selected foods
    string userChoice = "nada";
    int userNum = 0;
    bool validChoice = false;
    bool userCont = true;
    Food total;
    double dCals = 2000.0; //cal
    double dFat = 70.0; //g
    double dSugar = 30.0; //g
    double dProtein = 50.0; //g
    double dSodium = 2300.0; //mg
    
    MakeMenu();
    
    // Initial display
    cout << "\n\n\tWelcome! Please select or add a menu item.";
    cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
    do {
        cout << "\n\tType \"create\" add a new menu item.\n";
        for (int i = 0; i < menu.size(); i++) {
            cout << "\n\t" << (i + 1) << ". " << menu.at(i).getName() << endl;
        }
        cout << "\n\tType \"Quit\" to finish selecting.";
        // Input taker/checker
        do {
            cout << "\n\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            cout << "\n\tYour selection: ";
            cin >> userChoice;
            cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            
            if ((userChoice == "create") || (userChoice == "Create") || (userChoice == "C") || (userChoice == "c")) {
                NewItem();
                break;
            }
            else if ((userChoice == "q") || (userChoice == "quit") || (userChoice == "Q") || (userChoice == "Quit")) {
                break;
            }
            userNum = atoi(userChoice.c_str());
            
            if ((userNum > 0) && (userNum <= menu.size())) {
                validChoice = true;
                // Add up the values for the full total
                total = total + menu.at(userNum - 1);
                meal.push_back(menu.at(userNum - 1));
            }
            else {
                cout << "\n\tError, please try again.";
                validChoice = false;
            }
            
        } while (validChoice != true);
        
        // display list of chosen foods
        cout << "\n\tCurrently selected items:\n";
        for (int i = 0; i < meal.size(); i++) {
            cout << "\t" << (i + 1) << ". " << meal.at(i).getName() << endl;
        }
        cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        
        //Exit check
        if ((userChoice == "q") || (userChoice == "quit") || (userChoice == "Q") || (userChoice == "Quit")) {
            userCont = false;
        }
        else {
            userCont = true;
        }
        
    } while (userCont != false);
    
    //display totals
    cout << "\n\tTotal Calories: " << total.getEnergy() << endl;
    cout << "\tTotal Fat: " << total.getFat() << " g\n";
    cout << "\tTotal Sugar: " << total.getSugar() << " g\n";
    cout << "\tTotal Protein: " << total.getProtein() << " g\n";
    cout << "\tTotal Sodium: " << total.getSodium() << " mg\n";
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
    cout << "\n\tDaily Calorie amount: " << dCals << endl;
    cout << "\tDaily Fat amount: " << dFat << " g\n";
    cout << "\tDaily Sugar amount: " << dSugar << " g\n";
    cout << "\tDaily Protein amount: " << dProtein << " g\n";
    cout << "\tDaily Sodium amount: " << dSodium << " mg\n";
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    //Check if any values are above the daily intake
    if (total.getEnergy() > dCals) {
        cout << "\tYour calorie count is " << total.getEnergy() - dCals << " above the daily amount.\n";
    }
    if (total.getFat() > dFat) {
        cout << "\tYour fat content is " << total.getFat() - dFat << " g above the daily amount.\n";
    }
    if (total.getSugar() > dSugar) {
        cout << "\tYour sugar content is " << total.getSugar() - dSugar << " g above the daily amount.\n";
    }
    if (total.getProtein() > dProtein) {
        cout << "\tYour protein content is " << total.getProtein() - dProtein << " g above the daily amount.\n";
    }
    if (total.getSodium() > dSodium) {
        cout << "\tYour Sodium content is " << total.getSodium() - dSodium << " mg above the daily amount.\n";
    }
    
        cout << "\n\n\n\tHave great day!\n\n\n";
    return 0;
}

void MakeMenu() {
    // Build set list of foods and give them food stats
    // Build class members: Name,    cals,    fat,     sugar,   protein,    sodium
    Food f1("Cinnamon Raisin Bagel", 361.0, 2.2, 7.9, 13.0, 426.0);
    Food f2("Coffee Cake slice", 178.0, 5.4, 16.5, 3.1, 236.0);
    Food f3("Roasted Chicken Thigh", 279, 17.5, 0.0, 28.3, 95.0);
    Food f4("Mixed Vegetables", 88.0, 0.6, 0.0, 3.5, 549.0);
    Food f5("Breaded Catfish", 199.0, 11.6, 0.0, 15.7, 244.0);
    Food f6("Cappuccino", 73.0, 4.0, 5.3, 4.0, 47.0);
    Food f7("Egg noodles", 211.0, 2.5, 0.6, 8.1, 19.0);
    Food f8("Cannoli", 374.0, 17.0, 34.0, 10.0, 88.0);
    Food f9("Chicken Soup, with dumplings", 96, 5.5, 0.8, 5.6, 860.0);
    Food f10("California roll", 129, 4.7, 1.7, 3.0, 269.0);
    
    // Push back members into menu vector
    menu.push_back(f1);
    menu.push_back(f2);
    menu.push_back(f3);
    menu.push_back(f4);
    menu.push_back(f5);
    menu.push_back(f6);
    menu.push_back(f7);
    menu.push_back(f8);
    menu.push_back(f9);
    menu.push_back(f10);
    
}

void NewItem() {
    Food item;
    string n = "hubert";
    double p = 0;
    cin.ignore(1, '\n'); // Needed to fix getline
    
    cout << "\n\tPlease enter name of food: ";
    getline(cin, n);
    item.setName(n);
    
    cout << "\n\tPlease enter calories: ";
    cin >> n;
    p = atof(n.c_str()); // convert string to double to prevent crash
    item.setEnergy(p);
    
    cout << "\n\tPlease enter fat(g): ";
    cin >> n;
    p = atof(n.c_str()); // convert string to double to prevent crash
    item.setFat(p);
    
    cout << "\n\tPlease enter sugar(g): ";
    cin >> n;
    p = atof(n.c_str()); // convert string to double to prevent crash
    item.setSugar(p);
    
    cout << "\n\tPlease enter protein(g): ";
    cin >> n;
    p = atof(n.c_str()); // convert string to double to prevent crash
    item.setProtein(p);
    
    cout << "\n\tPlease enter sodium(mg): ";
    cin >> n;
    p = atof(n.c_str()); // convert string to double to prevent crash
    item.setSodium(p);
    
    menu.push_back(item);
}