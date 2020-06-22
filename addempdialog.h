#ifndef ADDEMPDIALOG_H
#define ADDEMPDIALOG_H

#include <QDialog>
#include <QAbstractButton>
#include "emp.h"

namespace Ui {
class AddEmpDialog;
}

class AddEmpDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddEmpDialog(QWidget *parent = nullptr,bool editing=false, Emp *emp=nullptr);
    ~AddEmpDialog();


    Emp *getEmpInDialog() const;
    void setEmpInDialog(Emp *value);

    bool getEditing() const;
    void setEditing(bool value);

private slots:

    void on_anuuler_clicked();
    void on_Ok_clicked();

private:
    Ui::AddEmpDialog *ui;
    Emp *empInDialog = new Emp();
    bool editing = false;
};

#endif // ADDEMPDIALOG_H
