#ifndef EMP_H
#define EMP_H

#include <QWidget>


class Emp
{


public:
    int getIdEmp() const;
    void setIdEmp(int value);

    QString &getFName() const;
    void setFName(const QString &value);

    QString &getLName() const;
    void setLName(const QString &value);

    QString &getBirthDate() const;
    void setBirthDate(const QString &value);

    QString &getAdress() const;
    void setAdress(const QString &value);

    QString &getProfession() const;
    void setProfession(const QString &value);

private:
    int idEmp;
    QString& fName;
    QString& lName;
    QString& birthDate;
    QString& adress;
    QString& profession;

};

#endif // EMP_H
