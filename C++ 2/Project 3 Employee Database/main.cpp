#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "employee.h"

using namespace std;

int main() {
    
    string userSelection = "cheese";
    string newName = "John Man, the manliest man";
    string newJob = "Lumber Jack";
    double newWage = 0.0;
    int userNumber = 0;
    bool validChoice = false;
    bool leave = false;
    vector<Employee> workers;
    
    Employee e1("Jackson Jackman", "Fixes icecream machine", 12.5);
    Employee e2("Garry Pokeman", "Animal wrangler", 10.6);
    Employee e3("Yopi Dope", "Math guy", 16.0);
    
    workers.push_back(e1);
    workers.push_back(e2);
    workers.push_back(e3);
    
    // INTRO TO USER INTERFACE
    cout << "\n\n\tWelcome to the Employee Database!\n";
    
    do {
        cout << "\tPlease select from the list below.\n";
        cout << "\t--------------------------------\n";
        cout << "\t  1. Print list of employees\n";
        cout << "\t  2. Calculate total wages\n";
        cout << "\t  3. Add new employee\n";
        cout << "\t  4. Exit application\n";
        cout << "\t--------------------------------\n\n";
        
        // SET UP INVALID SELECTION LOOP
        do {
            cout << "\tYour selection here: ";
            cin >> userSelection;
            userNumber = atoi(userSelection.c_str());
            
            if ((userNumber > 0) && (userNumber < 5)) {
                validChoice = true;
            }
            else {
                cout << "\n\tInvalid choice, please use numbers.\n\n";
                validChoice = false;
            }
            
        } while (validChoice == false);
        
        cin.ignore(1, '\n'); // Needed to fix getline
        
        switch (userNumber) {
            case 1: 
                // PRINT LIST
                for (int i = 0; i < workers.size(); i++) {
                    cout << "\n\tName: " << workers.at(i).getName() << "\n\t  Job: " << workers.at(i).getJob() << "\n\t  Wage: $" << workers.at(i).getWage() << " per hour\n";
                }
                cout << "\n\n";
                break;
            case 2: {
                // CALC WAGE
                double totWag = 0.0;
                double hours = 0.0;
                for (int i = 0; i < workers.size(); i++) {
                    cout << "\n\tHow many hours has " << workers.at(i).getName() << " worked? ";
                    cin >> hours;
                    totWag += (hours * workers.at(i).getWage());
                }
                cout << "\n\tTotal wages: $" << totWag << "\n\n";
                } break;
            case 3: {
                // ADD PERSON
                cout << "\n\n\tEnter employee's name: ";
                getline(cin, newName);
                cout << "\n\tEnter employee's job: ";
                getline(cin, newJob);
                cout << "\n\tEnter employee's hourly rate: $";
                cin >> newWage;
                cout << "\n\n";
                
                Employee e4(newName, newJob, newWage);
                workers.push_back(e4);
                } break;
            case 4:
                // LEAVE!
                cout << "\n\n\tHave a nice day!\n\n\n\n";
                leave = true;
                break;
            default:
                // Not sure yet
                cout << "\terror!\n";
                break;
        }
    } while (leave == false);
    
    return 0;
}