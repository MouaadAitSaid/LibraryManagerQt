#include "bookdao.h"
#include <QDebug>
#include "databaseconnector.h"

BookDAO::BookDAO()
{

}

bool BookDAO::insert(Book newBook)
{
    qDebug() << QString::fromStdString(newBook.toString());
    std::string query = "INSERT INTO book ( title, authors, tags,resume, entrydate )  VALUES (";
    query += " '"+newBook.getTitle()+"',";
    query += " '"+newBook.getAuthors().join(";").toStdString()+"',";
    query += "'"+newBook.getTags().join(";").toStdString()+"',";
    query += " '"+newBook.getResume()+"',";
    query += "'"+newBook.getEntryDate()+"'";
    query += " );";
    std::string copyQuery = "";
    qDebug() << QString::fromStdString(query);
    bool result = DatabaseConnector::executeQuery(query) && DatabaseConnector::executeQuery(copyQuery) ;

    if(result){
        qDebug()<< QString::fromStdString("Executed successfully");
        return true;
    }else{
        QSqlDatabase lmDatabase = QSqlDatabase::database();
        qDebug()<< QString::fromStdString("not Executed") << lmDatabase.lastError();
        return false;
    }
}
