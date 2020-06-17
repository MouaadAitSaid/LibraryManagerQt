#include "empbookdialog.h"
#include "ui_empbookdialog.h"

EmpBookDialog::EmpBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EmpBookDialog)
{
    ui->setupUi(this);
}

EmpBookDialog::~EmpBookDialog()
{
    delete ui;
}
