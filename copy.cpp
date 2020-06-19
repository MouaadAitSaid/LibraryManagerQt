#include "copy.h"


int Copy::getIdCopy() const
{
    return idCopy;
}

void Copy::setIdCopy(int value)
{
    idCopy = value;
}

QString &Copy::getRang() const
{
    return rang;
}

void Copy::setRang(const QString &value)
{
    rang = value;
}

QString &Copy::getBuyingDate() const
{
    return buyingDate;
}

void Copy::setBuyingDate(const QString &value)
{
    buyingDate = value;
}

Book Copy::getBook() const
{
    return book;
}

void Copy::setBook(const Book &value)
{
    book = value;
}
