#include "emp.h"




Emp::Emp()
{

}

std::string Emp::toString(){
    return "Nom et Prénom: " + this->getFName() + " " + this->getLName()
          + "\nDate de naissance: "+this->getBirthDate()
            + "\nTravail: " + this->getProfession();
}

bool Emp::validate()
{
    return !getFName().empty() &&
            !getLName().empty() &&
            !getAdress().empty() &&
            !getProfession().empty()  &&
            !getBirthDate().empty();
}

int Emp::getIdEmp() const
{
    return idEmp;
}

void Emp::setIdEmp(int value)
{
    idEmp = value;
}

std::string Emp::getFName() const
{
    return fName;
}

void Emp::setFName(const std::string &value)
{
    fName = value;
}

std::string Emp::getLName() const
{
    return lName;
}

void Emp::setLName(const std::string &value)
{
    lName = value;
}

std::string Emp::getBirthDate() const
{
    return birthDate;
}

void Emp::setBirthDate(const std::string &value)
{
    birthDate = value;
}

std::string Emp::getAdress() const
{
    return adress;
}

void Emp::setAdress(const std::string &value)
{
    adress = value;
}

std::string Emp::getProfession() const
{
    return profession;
}

void Emp::setProfession(const std::string &value)
{
    profession = value;
}

