#include "salary.h"


Salary::Salary(double annualSalary) : annualSalary(annualSalary) {}

double Salary::calculatePay() const {
    return annualSalary / 12; // Monthly salary
}

Payment* Salary::clone() const {
    return new Salary(*this);
}

