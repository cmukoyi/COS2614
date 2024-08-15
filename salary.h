#ifndef SALARY_H
#define SALARY_H

#include "payment.h"

class Salary : public Payment {
public:
    Salary(double annualSalary);

    double calculatePay() const override;
    Payment* clone() const override; // Implement cloning

private:
    double annualSalary;
};

#endif // SALARY_H
