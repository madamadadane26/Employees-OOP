#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;

// Employee base class
class Employee {
public:
    Employee(string name, int id, char empClass);
    virtual double calculateSalary(double profit) = 0;
    virtual void printInfo();

    string getName();
    int getId();
    char getEmpClass();
    double getSalary();

    friend istream& operator>>(istream& input, Employee& emp);
    friend ostream& operator<<(ostream& output, const Employee& emp);

protected:
    string name;
    int id;
    char empClass;
    double salary;
};

// Owner subclass
class Owner : public Employee {
public:
    Owner(string name, int id);
    double calculateSalary(double profit) override;
};

// Chef subclass
class Chef : public Employee {
public:
    Chef(string name, int id, string cuisine);
    double calculateSalary(double profit) override;
    void printInfo() override;
    string getCuisine();

private:
    string cuisine;
};

// Waiter subclass
class Waiter : public Employee {
public:
    Waiter(string name, int id, int yearsOfService);
    double calculateSalary(double profit) override;
    void printInfo() override;
    int getYearsOfService();

private:
    int yearsOfService;
};

#endif
