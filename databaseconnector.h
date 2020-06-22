#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H

#include <QtSql>
#include <QSqlDatabase>
#include <QWidget>
#include <QtDebug>

class DatabaseConnector
{

public:
    static void connect(){
        QSqlDatabase lmDatabase;
        lmDatabase = QSqlDatabase::addDatabase("QSQLITE");
        lmDatabase.setDatabaseName("C:/sqlite/qtlibmanager.db");
        lmDatabase.open();
    };
    static bool testConn(){
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        return lmDatabase.isOpen();
    };
    static bool executeQuery(const std::string query){
        QSqlQuery  queryHandler;
        return queryHandler.exec(QString::fromStdString(query));
    };
    
};

#endif // DATABASECONNECTOR_H
