#ifndef DAO_H
#define DAO_H

#include <QObject>

class DAO {
   public:
    virtual void getAll();
    virtual void getById();
    virtual void insert();
    virtual void update();
    virtual void remove();
};

#endif // DAO_H
