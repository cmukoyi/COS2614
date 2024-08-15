#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include "payment.h"

class Employee
{
public:
    Employee(const QString& firstName, const QString& surname, Payment* payment);

    // Copy constructor
    Employee(const Employee& other);

    // Destructor
    ~Employee();

    Employee& operator=(const Employee& other);

    // Getters
    int getId() const;
    QString getFirstName() const;
    QString getSurname() const;
    Payment* getPayment() const;

    // Static function to get the next ID
    static int getNextID();

private:
    int id;
    QString firstName;
    QString surname;
    Payment* payment;
    static int nextID;  // Static member for next ID

    // Helper function to generate unique IDs
    static void incrementNextID();

};




#endif // EMPLOYEE_H
