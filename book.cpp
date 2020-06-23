#include "book.h"
#include <QtDebug>


Book::Book()
{

}

int Book::getIdBook() const
{
    return idBook;
}

void Book::setIdBook(int value)
{
    idBook = value;
}

std::string Book::getTitle() const
{
    return title;
}

void Book::setTitle(const std::string &value)
{
    title = value;
}

std::string Book::getEntryDate() const
{
    return entryDate;
}

void Book::setEntryDate(const std::string &value)
{
    entryDate = value;
}

QStringList Book::getAuthors() const
{
    return authors;
}

void Book::setAuthors(const QStringList &value)
{
    authors = value;
}

std::string Book::getResume() const
{
    return resume;
}

void Book::setResume(const std::string &value)
{
    resume = value;
}

QStringList Book::getTags() const
{
    return tags;
}

void Book::setTags(const QStringList &value)
{
    tags = value;
}

bool Book::validate()
{
   qDebug() << !getTags().empty() <<  !getTitle().empty() << !getResume().empty()<< !getAuthors().empty() <<!getEntryDate().empty();
    return !getTags().empty() &&
            !getTitle().empty() &&
            !getResume().empty() &&
            !getAuthors().empty()  &&
            !getEntryDate().empty();
}

int Book::getNumberCopies() const
{
    return numberCopies;
}

void Book::setNumberCopies(int value)
{
    numberCopies = value;
}

std::string Book::toString(){
    return "Titres: " + this->getTitle()
            + "\copies: " + std::to_string(this->getNumberCopies());
}
