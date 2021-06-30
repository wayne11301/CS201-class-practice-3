#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

using namespace std;

// General employee class
class Employee
{
public:
    Employee() {}
    // The part of the constructor that lets you
    // choose which parent class constructor to use
    // also lets you initialize fields in a compact way
    // This is like if the function body had name = _name;
    Employee(string _name) : name(_name) {}
    string getName() { return name; }

    // Functions to override

    // What to do after Employee is paid
    // Default is to do nothing
    virtual void afterPay() {}
    // What to pay the Employee
    virtual float getPay() = 0;

protected:
    string name;

};

// Class for employees who have an annual salary
class Salaried : public Employee {
    int salary; // annual salary
    const int CHECKS_PER_YR = 12; // paid monthly
public:
    Salaried() { salary = 0; }
    Salaried(string _name, int _salary) : Employee(_name), salary(_salary) {}
    float getPay() { return ((float)salary) / CHECKS_PER_YR; }
};

// Class for employees paid with an hourly wage
// TODO: fill in the implementation of the class
// Remember to override afterPay()
class Hourly : public Employee {
    float rate;
    int totalhr;
public:
    Hourly() { rate = 0; totalhr = 0; }
    Hourly(string _name, float _rate) : Employee(_name), rate(_rate) { totalhr = 0; }
    void addHours(int _hours) { totalhr= _hours+totalhr; }
    float getPay() { return rate*totalhr; }
    void afterPay() {
        totalhr = 0;
    }
};

#endif // EMPLOYEE_H
