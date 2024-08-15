#include <QCoreApplication>
#include <QDebug>
#include "employeeList.h"
#include "salary.h"
#include "hourly.h"
#include "commission.h"

void printEmployeeReport(const EmployeeList& list) {
    qDebug() << "Employee Report:";

    double totalSalaried = 0.0;
    double totalHourly = 0.0;
    double totalCommission = 0.0;

    for (const Employee* employee : list) {
        qDebug() << "ID:" << employee->getId()
                 << ", Name:" << employee->getFirstName() << employee->getSurname();

        Payment* payment = employee->getPayment();
        if (dynamic_cast<Salary*>(payment)) {
            double pay = payment->calculatePay();
            totalSalaried += pay;
            qDebug() << "  Salary:" << pay;
        } else if (dynamic_cast<Hourly*>(payment)) {
            double pay = payment->calculatePay();
            totalHourly += pay;
            qDebug() << "  Hourly:" << pay;
        } else if (dynamic_cast<Commission*>(payment)) {
            double pay = payment->calculatePay();
            totalCommission += pay;
            qDebug() << "  Commission:" << pay;
        }
    }

    qDebug() << "\nSummary:"
             << "\nTotal Salaried:" << totalSalaried
             << "\nTotal Hourly:" << totalHourly
             << "\nTotal Commission:" << totalCommission;
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Create an EmployeeList
    EmployeeList list;

    // Add Employees
    list.append(new Employee("John", "Doe", new Salary(60000)));
    list.append(new Employee("Jane", "Smith", new Hourly(20.0, 160))); // 160 hours
    list.append(new Employee("Jim", "Brown", new Commission(30000, 0.10, 50000))); // 10% commission
    list.append(new Employee("Jill", "White", new Salary(70000)));
    list.append(new Employee("Jake", "Black", new Hourly(25.0, 120))); // 120 hours
    list.append(new Employee("Julie", "Green", new Commission(25000, 0.15, 60000))); // 15% commission

    // Modify some payments
    Hourly* hourlyPayment = dynamic_cast<Hourly*>(list[1]->getPayment());
    if (hourlyPayment) {
        hourlyPayment->addHours(20); // Add 20 more hours
    }

    Commission* commissionPayment = dynamic_cast<Commission*>(list[2]->getPayment());
    if (commissionPayment) {
        commissionPayment->addSales(10000); // Add $10,000 in sales
    }

    // Print report
    printEmployeeReport(list);

    // Clean up
    qDeleteAll(list); // Deletes all Employee pointers in the list

    return a.exec();
}
