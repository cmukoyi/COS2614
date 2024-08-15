#ifndef COMMISSION_H
#define COMMISSION_H

#include "payment.h"

class Commission : public Payment {
public:
    Commission(double baseSalary, double commissionRate, double salesAmount);

    double calculatePay() const override;
    Payment* clone() const override; // Implement cloning
    void addSales(double sales); // Function to add sales

private:
    double baseSalary;
    double commissionRate;
    double salesAmount;
};

#endif // COMMISSION_H
