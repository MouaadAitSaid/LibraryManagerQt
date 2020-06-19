#include "emp.h"


int Emp::getIdEmp() const
{
    return idEmp;
}

void Emp::setIdEmp(int value)
{
    idEmp = value;
}

QString &Emp::getFName() const
{
    return fName;
}

void Emp::setFName(const QString &value)
{
    fName = value;
}

QString &Emp::getLName() const
{
    return lName;
}

void Emp::setLName(const QString &value)
{
    lName = value;
}

QString &Emp::getBirthDate() const
{
    return birthDate;
}

void Emp::setBirthDate(const QString &value)
{
    birthDate = value;
}

QString &Emp::getAdress() const
{
    return adress;
}

void Emp::setAdress(const QString &value)
{
    adress = value;
}

QString &Emp::getProfession() const
{
    return profession;
}

void Emp::setProfession(const QString &value)
{
    profession = value;
}
