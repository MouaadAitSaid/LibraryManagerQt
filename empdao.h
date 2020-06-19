#ifndef EMPDAO_H
#define EMPDAO_H

#include "DAO.h"

class EmpDAO: public DAO
{
public:
    EmpDAO();
    void getAll();
    void getById();
    void insert();
    void update();
    void remove();
};

#endif // EMPDAO_H
