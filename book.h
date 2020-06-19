#ifndef BOOK_H
#define BOOK_H

#include <QWidget>
#include <QList>
#include "emp.h"



class Book
{
public:

    int getIdBook() const;
    void setIdBook(int value);

    QString &getTitle() const;
    void setTitle(const QString &value);

    QString &getEntryDate() const;
    void setEntryDate(const QString &value);

    QString &getResume() const;
    void setResume(const QString &value);

    QList<QString *> getAuthors() const;
    void setAuthors(const QList<QString *> &value);

    QList<QString *> getTags() const;
    void setTags(const QList<QString *> &value);

private:
    int idBook;
    QString& title;
    QString& entryDate;
    QList<QString *> authors;
    QString& resume;
    QList<QString *> tags;
};

#endif // BOOK_H
