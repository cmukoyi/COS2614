#ifndef HOURLY_H
#define HOURLY_H

#include "payment.h"

class Hourly : public Payment {
public:
    Hourly(double hourlyRate, int hoursWorked);

    double calculatePay() const override;
    Payment* clone() const override; // Implement cloning
    void addHours(int hours); // Function to add hours

private:
    double hourlyRate;
    int hoursWorked;
};

#endif // HOURLY_H
