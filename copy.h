#ifndef COPY_H
#define COPY_H

#include <QWidget>
#include "book.h"
#include "emp.h"

class Copy
{

public:
   Copy();

private:
    int idCopy;
    std::string rang;
    std::string buyingDate;
    Book book;
    Emp emp;
};

#endif // COPY_H
