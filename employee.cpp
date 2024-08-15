#include "employee.h"

// Initialize static member
int Employee::nextID = 1001;

Employee::Employee(const QString& firstName, const QString& surname, Payment* payment)
    : id(nextID), firstName(firstName), surname(surname), payment(payment) {
    incrementNextID();
}

Employee::Employee(const Employee& other)
    : id(other.id), firstName(other.firstName), surname(other.surname) {
    // Deep copy the Payment object
    if (other.payment) {
        payment = other.payment->clone(); // Assuming a clone method in Payment
    } else {
        payment = nullptr;
    }
}

Employee::~Employee() {
    delete payment; // Deallocate memory
}

Employee& Employee::operator=(const Employee& other) {
    if (this != &other) {
        // Clean up existing resource
        delete payment;

        // Copy data
        id = other.id;
        firstName = other.firstName;
        surname = other.surname;

        // Deep copy the Payment object
        if (other.payment) {
            payment = other.payment->clone(); // Assuming a clone method in Payment
        } else {
            payment = nullptr;
        }
    }
    return *this;
}

int Employee::getId() const {
    return id;
}

QString Employee::getFirstName() const {
    return firstName;
}

QString Employee::getSurname() const {
    return surname;
}

Payment* Employee::getPayment() const {
    return payment;
}

int Employee::getNextID() {
    return nextID;
}

void Employee::incrementNextID() {
    ++nextID;
}

