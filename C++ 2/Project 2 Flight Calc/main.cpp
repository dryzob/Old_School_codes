#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include "func.h"

using namespace std;

int main() {
    
    // ~Earth's radius in miles
    const double RADIUS = 3958.8;
    
    // current avaliable locations
    vector<string> locations = {"Raleigh, NC, USA", "San Diego, CA, USA", "Las Vegas, NV, USA",
                                "Atlanta, GA, USA", "Fresno, TX, USA", "Brink, NJ, USA", "Salem, OR, USA",
                                "Post Falls, ID, USA", "Colorado Springs, CO, USA", "Fort Myers, FL, USA"};
    // corresponding latitude
    vector<double> latitude = {35.639954, 32.715736, 36.114647, 33.753746, 29.540457, 40.060272, 44.944099,
                               47.712257, 38.846127, 26.640629};
    // corresponding longitude
    vector<double> longitude = {-78.644257, -117.161087, -115.172813, -84.549934, -95.448189, -74.139343,
                                -123.040283, -116.948364, -104.800644, -81.872307};
    bool userCont = false;
    bool validChoice = false;
    string userChoice = "1";
    int userNum1 = 0;
    int userNum2 = 0;
    double userLat1 = 0.0;
    double userLong1 = 0.0;
    double userLat2 = 0.0;
    double userLong2 = 0.0;
    double calcDis = 0.0;
    double calcTime = 0.0;
    
    while (userCont == false) {

        // Intro    
        cout << "\n\n\tWelcome! Please select your starting location.\n\n";
        
        for (int i = 0; i < locations.size(); ++i) {
            cout << "\n\t" << (i + 1) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
        }
        
        do { // The departure location user choice
            cout << "\n\n\tType number here: ";
            cin >> userChoice;
            cout << endl;
            // convert string into number
            userNum1 = atoi(userChoice.c_str()) - 1;
            
            if ((userNum1 >= 0) && (userNum1 <= 9)) {
                validChoice = true;
            }
            else {
                // restates list for input
                cout << "\n\tPlease enter a valid number.\n";
                
            for (int i = 0; i < locations.size(); ++i) {
                cout << "\n\t" << (i + 1) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
            }
                validChoice = false;
            }
            
        } while (!(validChoice == true));
        
        // records lat and long for calculation
        userLat1 = latitude.at(userNum1);
        userLong1 = longitude.at(userNum1);
        
        for (int i = 0; i < locations.size(); ++i) {
            if (i < userNum1) {
                cout << "\n\t" << (i + 1) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
            }
            else if (i > userNum1) {
                cout << "\n\t" << (i) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
            }
        }
        
        do { // The destination location user choice
            cout << "\n\n\tType number here: ";
            cin >> userChoice;
            cout << endl;
            // convert string into number
            userNum2 = stoi(userChoice) - 1;
            
            if ((userNum2 >= 0) && (userNum2 <= 8)) {
                validChoice = true;
            }
            else {
                // restates previous list to prompt input
                cout << "\n\tPlease enter a valid number.\n";
                
                for (int i = 0; i < locations.size(); ++i) {
                    if (i < userNum1) {
                        cout << "\n\t" << (i + 1) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
                    }
                    else if (i > userNum1) {
                        cout << "\n\t" << (i) << ". " << locations.at(i) << "\t\t\t" << latitude.at(i) << "\t" << longitude.at(i) << "\n";
                }
            }
                validChoice = false;
            }
            
        } while (!(validChoice == true));
        
        // Corrects index location for userNum2 and records for calculation
        if (userNum2 >= userNum1) {
            userLat2 = latitude.at(userNum2 + 1);
            userLong2 = longitude.at(userNum2 + 1);
        } 
        else {
            userLat2 = latitude.at(userNum2);
            userLong2 = longitude.at(userNum2);
        }
        
        // calculations using functions and outputting
        calcDis = haversine(userLat1, userLat2, userLong1, userLong2, RADIUS);
        calcTime = getFlgihtTime(userLat1, userLat2, userLong1, userLong2);
        
        cout << "\tThe estimated distance is: " << calcDis << " miles\n";
        cout << "\tThe estimated time is: " << calcTime << " hours\n";
        
        // asks user if they want to use the program again, ends on no
        do {
            
            cout << "\n\tAre you finished checking flights? yes or no\n\tYour response: ";
            cin >> userChoice;
            
            if ((userChoice == "no") || (userChoice == "n") || (userChoice == "No") || (userChoice == "nah")) {
                userCont = false; // Loop ender
                validChoice = true;
            }
            else if ((userChoice == "yes") || (userChoice == "y") || (userChoice == "Yes") || (userChoice == "yee")) {
                cout << "\n\tHave a wonderful day!\n\n";
                userCont = true;
                validChoice = true;
            }
            else {
                cout << "\n\tSay again?\n";
                validChoice = false;
            }
        } while (!(validChoice == true));
    }
    
    return 0;
}
/* Locations
1. Raleigh, NC, USA  35.639954  -78.644257
2. San Diego, CA, USA  32.715736  -117.161087
3. Las Vegas, NV, USA  36.114647  -115.172813
4. Atlanta, GA, USA  33.753746  -84.549934
5. Fresno, TX, USA  29.540457  -95.448189
6. Brink, NJ, USA  40.060272  -74.139343
7. Salem, OR, USA  44.944099  -123.040283
8. Post Falls, ID, USA  47.712257  -116.948364
9. Colorado Springs, CO, USA  38.846127  -104.800644
10. Fort Myers, FL, USA  26.640629  -81.872307
*/