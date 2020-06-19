#ifndef COPY_H
#define COPY_H

#include <QWidget>
#include "book.h"

class Copy
{

public:
    int getIdCopy() const;
    void setIdCopy(int value);

    QString &getRang() const;
    void setRang(const QString &value);

    QString &getBuyingDate() const;
    void setBuyingDate(const QString &value);

    Book getBook() const;
    void setBook(const Book &value);

private:
    int idCopy;
    QString& rang;
    QString& buyingDate;
    Book book;
};

#endif // COPY_H
