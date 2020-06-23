#ifndef BOOK_H
#define BOOK_H

#include <QWidget>




class Book
{
public:
    Book();


    int getIdBook() const;
    void setIdBook(int value);

    std::string getTitle() const;
    void setTitle(const std::string &value);

    std::string getEntryDate() const;
    void setEntryDate(const std::string &value);

    QStringList getAuthors() const;
    void setAuthors(const QStringList &value);

    std::string getResume() const;
    void setResume(const std::string &value);

    QStringList getTags() const;
    void setTags(const QStringList &value);

    bool validate();

    int getNumberCopies() const;
    void setNumberCopies(int value);

    std::string toString();

private:
    int idBook;
    std::string  title;
    std::string  entryDate;
    QStringList authors;
    std::string  resume;
    QStringList tags;
    int numberCopies;
};

#endif // BOOK_H
