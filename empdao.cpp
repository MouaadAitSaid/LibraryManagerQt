#include "emp.h"
#include "empdao.h"
#include "databaseconnector.h"
#include <QDebug>

EmpDAO::EmpDAO()
{

}

QList<Emp *> EmpDAO::getAll(std::string search)
{
    QList<Emp *> emprunteurs;
    std::string query = "SELECT * FROM emp ";
    if(!search.empty()){
        query += "WHERE fname LIKE '%"+search+"%'";
        query += "OR lname LIKE '%"+search+"%'";
        query += "OR adress LIKE '%"+search+"%'";
        query += "OR birthdate LIKE '%"+search+"%'";
        query += "OR profession LIKE '%"+search+"%'";
    }
    QSqlQuery  queryHandler;
    bool executed =  queryHandler.exec(QString::fromStdString(query));
    if(!executed)
    {
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        qDebug()<< QString::fromStdString("not Executed") << lmDatabase.lastError();
        return emprunteurs;
    }else{
        qDebug()<< QString::fromStdString("Qeury Executed\n"+query);
        while(queryHandler.next()){
            Emp *tempEmp = new Emp();
            tempEmp->setIdEmp(queryHandler.value(0).toInt());
            tempEmp->setFName(queryHandler.value(1).toString().toStdString());
            tempEmp->setLName(queryHandler.value(2).toString().toStdString());
            tempEmp->setAdress(queryHandler.value(3).toString().toStdString());
            tempEmp->setBirthDate(queryHandler.value(4).toString().toStdString());
            tempEmp->setProfession(queryHandler.value(5).toString().toStdString());
            emprunteurs << tempEmp;
        }
        return emprunteurs;
    }


}

bool EmpDAO::insert(const Emp &newEmp)
{
    std::string query = "INSERT INTO emp (fname,lname,adress,birthdate,profession) VALUES (";
    query += "'"+newEmp.getFName()+"',";
    query += "'"+newEmp.getLName()+"',";
    query += "'"+newEmp.getAdress()+"',";
    query += "'"+newEmp.getBirthDate()+"',";
    query += "'"+newEmp.getProfession();
    query+=  "');";
    qDebug() << QString::fromStdString(query);
    bool result = DatabaseConnector::executeQuery(query);
    if(result){
        qDebug()<< QString::fromStdString("Executed successfully");
        return true;
    }else{
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        qDebug()<< QString::fromStdString("not Executed") << lmDatabase.lastError();
        return false;
    }
}

bool EmpDAO::update(const Emp &oldEmp)
{
    std::string query = "UPDATE emp SET ";
    query += "fname = '"+oldEmp.getFName()+"',";
    query += "lname = '"+oldEmp.getLName()+"',";
    query += "adress = '"+oldEmp.getAdress()+"',";
    query += "birthdate = '"+oldEmp.getBirthDate()+"',";
    query += "profession = '"+oldEmp.getProfession()+"'";
    query +=  " WHERE idEmp = '"+std::to_string(oldEmp.getIdEmp())+"';" ;
    qDebug() << QString::fromStdString(query);
    bool result = DatabaseConnector::executeQuery(query);
    if(result){
        qDebug()<< QString::fromStdString("Executed successfully");
        return true;
    }else{
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        qDebug()<< QString::fromStdString("not Executed") << lmDatabase.lastError();
        return false;
    }
}

bool EmpDAO::remove(int id)
{
    std::string query = "DELETE FROM emp WHERE idEmp = '"+std::to_string(id)+"'";
    qDebug() << QString::fromStdString(query);
    bool result = DatabaseConnector::executeQuery(query);
    if(result){
        qDebug()<< QString::fromStdString("Executed successfully");
        return true;
    }else{
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        qDebug()<< QString::fromStdString("not Executed") << lmDatabase.lastError();
        return false;
    }
};


