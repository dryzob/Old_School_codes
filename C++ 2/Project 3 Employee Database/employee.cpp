#include "employee.h"

Employee::Employee() {
    name = "unlisted";
    job = "unlisted";
    wage = 0.0;
}

Employee::Employee(string n, string j, double w) {
    name = n;
    job = j;
    
    if (w < 0) {
        wage = 0;
    } else {
        wage = w;
    }
}

void Employee::setName(string n) {
    name = n;
}

void Employee::setJob(string j) {
    job = j;
}

void Employee::setWage(double w) {
    if (w < 0) {
        wage = 0;
    } else {
        wage = w;
    }
}

string Employee::getName() const {
    return name;
}

string Employee::getJob() const {
    return job;
}

double Employee::getWage() const {
    return wage;
}