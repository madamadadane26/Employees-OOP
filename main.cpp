#include "Employee.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;
//driver
// Print the information of an Employee object
void printEmployeeInfo(Employee* emp) {
    emp->printInfo();
}

int main() {
    vector<Employee*> employees;

    employees.push_back(new Owner("John Doe", 1));
    employees.push_back(new Chef("Mario Rossi", 2, "Italian"));
    employees.push_back(new Chef("Jean Dupont", 3, "French"));
    employees.push_back(new Waiter("Jane Smith", 4, 3));
    employees.push_back(new Waiter("Mark Johnson", 5, 5));
    employees.push_back(new Waiter("Linda Lee", 6, 7));

    int numMonths;
    do {
        cout << "Enter the number of months to calculate salaries for: ";
        cin >> numMonths;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (numMonths <= 0); // check if the input is valid

    double lowestProfit = numeric_limits<double>::max();
    int lowestMonth = -1;

    for (int i = 0; i < numMonths; i++) {
        double profit;
        do {
            cout << "-----------------------------------------------------" << endl;
            cout << "\nEnter profit for month " << i + 1 << ": $";
            cin >> profit;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (cin.fail()) {
                // invalid input, clear the error flags and show an error message
                cin.clear();
                cout << "Invalid input, please enter a valid number." << endl;
            }
        } while (cin.fail());

        double waiterTips[3];
        for (int j = 0; j < 3; j++) {
            do {
                cout << "Enter tips for Waiter " << j+1 << " in month " << i+1 << ": $";
                cin >> waiterTips[j];
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (cin.fail() || waiterTips[j] < 0) {
                    // invalid input, clear the error flags and show an error message
                    cin.clear();
                    cout << "Invalid input, please enter a positive number." << endl;
                }
            } while (cin.fail() || waiterTips[j] < 0);
        }

        // Calculate salaries
        double totalSalary = 0.0;
        for (Employee* emp : employees) {
            totalSalary += emp->calculateSalary(profit);
            if (emp->getEmpClass() == 'W') {
                int index = emp->getId() - 4;
                totalSalary += waiterTips[index];
            }
        }

        // Print employee stats and salaries
        cout << "\nEmployee stats for month " << i+1 << ":" << endl;
        cout << "-----------------------------------------------------" << endl;
        for (Employee* emp : employees) {
            printEmployeeInfo(emp);
        }
        cout << "-----------------------------------------------------" << endl;
        cout << "Total Salary: $" << totalSalary << endl;

        if (profit < lowestProfit) {
            lowestProfit = profit;
            lowestMonth = i+1;
        }
    }

    // Print the month with the lowest profit
    cout << "\nThe month with the lowest profit was month " << lowestMonth << " with a profit of $" << lowestProfit << endl;

    // Delete the employees
for (Employee* emp : employees) {
    delete emp;
}

return 0;
}
