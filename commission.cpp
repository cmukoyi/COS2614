#include "commission.h"


Commission::Commission(double baseSalary, double commissionRate, double salesAmount)
    : baseSalary(baseSalary), commissionRate(commissionRate), salesAmount(salesAmount) {}

double Commission::calculatePay() const {
    return baseSalary + (commissionRate * salesAmount);
}

Payment* Commission::clone() const {
    return new Commission(*this);
}

void Commission::addSales(double sales) {
    salesAmount += sales;
}
