#ifndM/l;k,g cdxwsq<

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
    static bool executeQuery(const QString& query, const QString& message){
        return true;
    };
    
};

#endif // DATABASECONNECTOR_H
