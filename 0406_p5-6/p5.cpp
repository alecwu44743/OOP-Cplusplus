#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;

public:
    Employee(string name, int id) : name(name), id(id) {}

    virtual double calculatePay() = 0;

    virtual void display() {
        cout << "Name: " << name << ", ID: " << id << endl;
    }
};

class CommissionEmployee : public Employee {
protected:
    double commissionRate;
    double sales;

public:
    CommissionEmployee(string name, int id, double commissionRate, double sales)
        : Employee(name, id), commissionRate(commissionRate), sales(sales) {}

    double calculatePay() override {
        return commissionRate * sales;
    }

    void display() override {
        Employee::display();
        cout << "Commission Employee" << endl;
    }
};

class BasePlusCommissionEmployee : public CommissionEmployee {
protected:
    double baseSalary;

public:
    BasePlusCommissionEmployee(string name, int id, double commissionRate,
                                double sales, double baseSalary)
        : CommissionEmployee(name, id, commissionRate, sales),
        baseSalary(baseSalary) {}

    double calculatePay() override {
        return baseSalary + CommissionEmployee::calculatePay();
    }

    void display() override {
        Employee::display();
        cout << "Base Plus Commission Employee" << endl;
    }
};

int main() {
    CommissionEmployee c("OOOO Chen", 123, 0.1, 10000);
    BasePlusCommissionEmployee b("Grace Sui", 456, 0.2, 20000, 5000);

    c.display();
    cout << "Pay: $" << c.calculatePay() << endl;

    cout << endl;

    b.display();
    cout << "Pay: $" << b.calculatePay() << endl;
    
    
    return 0;
}