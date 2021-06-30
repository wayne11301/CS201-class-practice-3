#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include "employee.h"

using namespace std;

// Add an employee
// TODO: prototype has a bug!
void hire(vector<Employee*> & workforce)
{
    string name;
    char type;

    cout << "Enter the employee's name: ";
    cin >> name;
    cout << "Enter s for salaried, h for hourly: ";
    cin >> type;
    if ('s' == type)
    {
        int sal;
        cout << "Enter annual salary (integer, $): ";
        cin >> sal;
        workforce.push_back(new Salaried(name,sal));
    }
    else if ('h' == type)
    {
        float rate;
        Hourly* emp;
        int hrs;
        cout << "Enter hourly pay rate (float, $): ";
        cin >> rate;
        emp = new Hourly(name, rate);
        cout << "Enter number of hours allotted: ";
        cin >> hrs;
        emp->addHours(hrs);
        // TODO: Add emp to workforce
        workforce.push_back(emp);
    }
    else
        cerr << "Unrecognized employee type: " << type;
}

// "Pay" employees -- output what each should get paid
void pay(vector<Employee*>& workforce) {
    if (workforce.begin() == workforce.end()) {
        cout << "There's no one to pay yet" << endl;
        return;
    }
    for (auto i = workforce.begin(); i != workforce.end(); i++) {
        cout << (*i)->getName()<<" $"<< (*i)->getPay()<<endl;
        (*i)->afterPay();
    }
    return;
}


int main()
{
    vector<Employee*> workforce;
    char cmd = ' ';

    cout << "Simple employment simulation" << endl;
    do
    {
        cout << "Enter a letter to choose a command:" << endl;
        cout << "q or Q: quit" << endl;
        cout << "h: hire an employee" << endl;
        cout << "p: pay employees" << endl;
        cin >> cmd;
        switch (cmd)
        {
            // TODO: add case for quit
        case 'h':
            hire(workforce);
            break;
        case 'p':
            pay(workforce);
            break;
            // TODO: add error handling case for unrecognized command
        case 'q':
            break;
        case 'Q':
            break;
        default:
            cout << "Unrecognized command " << cmd << endl<<"Please try again"<<endl;
        }
    } while (cmd != 'q' && cmd != 'Q');
}