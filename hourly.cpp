#include "hourly.h"


Hourly::Hourly(double hourlyRate, int hoursWorked)
    : hourlyRate(hourlyRate), hoursWorked(hoursWorked) {}

double Hourly::calculatePay() const {
    return hourlyRate * hoursWorked;
}

Payment* Hourly::clone() const {
    return new Hourly(*this);
}

void Hourly::addHours(int hours) {
    hoursWorked += hours;
}
