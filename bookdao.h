#ifndef BOOKDAO_H
#define BOOKDAO_H

#include  "book.h"


class BookDAO
{
public:
    BookDAO();

    static bool insert(Book newBook);
};

#endif // BOOKDAO_H
