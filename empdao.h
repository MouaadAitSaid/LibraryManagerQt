#ifndef EMPDAO_H
#define EMPDAO_H

#include "emp.h"


class EmpDAO
{
public:
    EmpDAO();
    static QList<Emp *> getAll(std::string search);
    void getById();
    static bool insert(const Emp &newEmp);
    static bool update(const Emp &newEmp);
    static bool remove(const int id);
};

#endif // EMPDAO_H
