#include <iostream>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string firstName;
    string lastName;
    int ssn;

public:
    Employee(string firstName, string lastName, int ssn)
        : firstName(firstName), lastName(lastName), ssn(ssn) {}

    virtual double earnings() = 0;

    virtual void print(){
        cout << "Name: " << firstName << " " << lastName << "\nSSN: " << ssn << endl;
    }
};

class SalariedEmployee : public Employee {
protected:
    double weeklySalary;

public:
    SalariedEmployee(string firstName, string lastName, int ssn, double weeklySalary)
        : Employee(firstName, lastName, ssn), weeklySalary(weeklySalary) {}

    double earnings() override {
        return weeklySalary;
    }

    void print() override {
        Employee::print();
        cout << "Weekly Salary: " << weeklySalary << endl;
        cout << "Earnings: " << earnings() << endl;
    }
};


class CommissionEmployee : public Employee {
protected:
    double commissionRate;
    double grossSales;

public:
    CommissionEmployee(string firstName, string lastName, int ssn, double commissionRate, double sales)
        : Employee(firstName, lastName, ssn), commissionRate(commissionRate), grossSales(sales) {}

    double earnings() override {
        return commissionRate * grossSales;
    }

    void print() override {
        Employee::print();
        cout << "grossSales: " << grossSales << endl;
        cout << "commissionRate: " << commissionRate << endl;
        cout << "Earnings: " << earnings() << endl;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee {
protected:
    double baseSalary;

public:
    BasePlusCommissionEmployee(string firstName, string lastName, int ssn, double commissionRate,
                                double sales, double baseSalary)
        : CommissionEmployee(firstName, lastName, ssn, commissionRate, sales),
        baseSalary(baseSalary) {}

    double earnings() override {
        return baseSalary + CommissionEmployee::earnings();
    }

    void print() override {
        Employee::print();
        cout << "grossSales: " << grossSales << endl;
        cout << "commissionRate: " << commissionRate << endl;
        cout << "baseSalary: " << baseSalary << endl;
        cout << "Earnings: " << earnings() << endl;
    }
};

int main() {
    SalariedEmployee salariedEmployee("Leleleleleo", "Chen", 111111111, 800);
    CommissionEmployee commissionEmployee("Avery", "Chen", 222222222, 0.1, 10000);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Rong Rong", "Liu", 333333333, 0.1, 5000, 300);

    salariedEmployee.print();
    cout << endl;

    commissionEmployee.print();
    cout << endl;

    basePlusCommissionEmployee.print();
    cout << endl;
}