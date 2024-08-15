#ifndef PAYMENT_H
#define PAYMENT_H

class Payment
{
public:
    virtual double calculatePay() const = 0; // Pure virtual function
    virtual Payment* clone() const = 0; // Pure virtual function for cloning
    virtual ~Payment() = default; // Virtual destructor

};

#endif // PAYMENT_H
