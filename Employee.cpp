#include "Employee.h"
#include <iostream>
#include <string>

using namespace std;

// Employee base class
Employee::Employee(string name, int id, char empClass) {
    this->name = name;
    this->id = id;
    this->empClass = empClass;
    this->salary = 0.0;
}

string Employee::getName() {
    return name;
}

int Employee::getId() {
    return id;
}

char Employee::getEmpClass() {
    return empClass;
}

double Employee::getSalary() {
    return salary;
}

void Employee::printInfo() {
    cout << "Name: " << name << endl;
    cout << "ID: " << id << endl;
    cout << "Employee Class: " << empClass << endl;
    cout << "Base Salary: $" << salary << endl;
}

istream& operator>>(istream& input, Employee& emp) {
    cout << "Enter employee information: " << endl;
    cout << "Name: ";
    getline(input, emp.name);
    cout << "ID: ";
    input >> emp.id;
    cout << "Employee Class (O for owner, C for chef, W for waiter): ";
    input >> emp.empClass;
    input.ignore();
    return input;
}

ostream& operator<<(ostream& output, const Employee& emp) {
    output << "Name: " << emp.name << endl;
    output << "ID: " << emp.id << endl;
    output << "Employee Class: " << emp.empClass << endl;
    output << "Base Salary: $" << emp.salary << endl;
    return output;
}

// Owner subclass
Owner::Owner(string name, int id) : Employee(name, id, 'O') {}

double Owner::calculateSalary(double profit) {
    double profitShare = 0.6 * profit;
    salary = 15000.0 + profitShare;
    return salary;
}

// Chef subclass
Chef::Chef(string name, int id, string cuisine) : Employee(name, id, 'C') {
    this->cuisine = cuisine;
}

double Chef::calculateSalary(double profit) {
    double profitShare = 0.2 * profit;
    salary = 10000.0 + profitShare;
    return salary;
}

string Chef::getCuisine() {
    return cuisine;
}

void Chef::printInfo() {
    Employee::printInfo();
    cout << "Cuisine: " << cuisine << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}

// Waiter subclass
Waiter::Waiter(string name, int id, int yearsOfService) : Employee(name, id, 'W') {
    this->yearsOfService = yearsOfService;
}

double Waiter::calculateSalary(double profit) {
    salary = 3000.0;
    return salary;
}

int Waiter::getYearsOfService() {
    return yearsOfService;
}

void Waiter::printInfo() {
    Employee::printInfo();
    cout << "Years of Service: " << yearsOfService << endl;
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
}