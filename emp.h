#ifndef EMP_H
#define EMP_H

#include <QWidget>
#include <QList>
#include "copy.h"


class Emp
{


public:
    Emp();
    int getIdEmp() const;
    void setIdEmp(int value);

    QList<Copy *> getCopies() const;
    void setCopies(const QList<Copy *> &value);

    std::string getFName() const;
    void setFName(const std::string &value);

    std::string getLName() const;
    void setLName(const std::string &value);

    std::string getBirthDate() const;
    void setBirthDate(const std::string &value);

    std::string getAdress() const;
    void setAdress(const std::string &value);

    std::string getProfession() const;
    void setProfession(const std::string &value);

    std::string toString();
    bool validate();

private:
    int idEmp;
    std::string fName;
    std::string lName;
    std::string birthDate;
    std::string adress;
    std::string profession;
    QList<Copy *> copies;

};

#endif // EMP_H
