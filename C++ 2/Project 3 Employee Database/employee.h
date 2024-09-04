#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

using namespace std;

class Employee {
    public:
    Employee();
    Employee(string n, string j, double w);
    
    void setName(string n);
    void setJob(string j);
    void setWage(double w);
    
    string getName() const;
    string getJob() const;
    double getWage() const;
    
    private:
    string name;
    string job;
    double wage;
    
};
#endif