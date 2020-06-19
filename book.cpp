#include "book.h"

int Book::getIdBook() const
{
    return idBook;
}

void Book::setIdBook(int value)
{
    idBook = value;
}

QString &Book::getTitle() const
{
    return title;
}

void Book::setTitle(const QString &value)
{
    title = value;
}

QString &Book::getEntryDate() const
{
    return entryDate;
}

void Book::setEntryDate(const QString &value)
{
    entryDate = value;
}

QString &Book::getAuthor() const
{
    return author;
}

void Book::setAuthor(const QString &value)
{
    author = value;
}

QString &Book::getResume() const
{
    return resume;
}

void Book::setResume(const QString &value)
{
    resume = value;
}

QString &Book::getDomaine() const
{
    return domaine;
}

void Book::setDomaine(const QString &value)
{
    domaine = value;
}

Emp Book::getEmp() const
{
    return emp;
}

void Book::setEmp(const Emp &value)
{
    emp = value;
}

QList<QString *> Book::getAuthors() const
{
    return authors;
}

void Book::setAuthors(const QList<QString *> &value)
{
    authors = value;
}

QList<QString *> Book::getTags() const
{
    return tags;
}

void Book::setTags(const QList<QString *> &value)
{
    tags = value;
}
