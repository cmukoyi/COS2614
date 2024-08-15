#ifndef EMPLOYEELIST_H
#define EMPLOYEELIST_H

#include <QList>
#include "employee.h"

class EmployeeList : public QList<Employee*> {
    // Inherits all member functions from QList<Employee*>
};

#endif // EMPLOYEELIST_H
