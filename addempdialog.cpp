#include "addempdialog.h"
#include "ui_addempdialog.h"
#include "emp.h"
#include "empdao.h"
#include <QDebug>
#include <QMessageBox>


AddEmpDialog::AddEmpDialog(QWidget *parent, bool editing, Emp *emp):
    QDialog(parent),
    ui(new Ui::AddEmpDialog)
{
    ui->setupUi(this);
    this->setEditing(editing);
    this->setEmpInDialog(emp);
    if(editing){
        ui->fNameText->setText(QString::fromStdString(emp->getFName()));
        ui->lNameText->setText(QString::fromStdString(emp->getLName()));
        ui->adressText->setText(QString::fromStdString(emp->getAdress()));
        ui->professionText->setText(QString::fromStdString(emp->getProfession()));
        ui->dateEdit->setDate(QDate::fromString(QString::fromStdString(emp->getBirthDate()),"dd/MM/yyyy"));

    }
}

AddEmpDialog::~AddEmpDialog()
{
    delete ui;
}

void AddEmpDialog::on_anuuler_clicked()
{
    this->close();
}

void AddEmpDialog::on_Ok_clicked()
{

    Emp newEmprunteur;
    newEmprunteur.setFName(ui->fNameText->toPlainText().toStdString());
    newEmprunteur.setLName(ui->lNameText->toPlainText().toStdString());
    newEmprunteur.setBirthDate(ui->dateEdit->text().toStdString());
    newEmprunteur.setAdress(ui->adressText->toPlainText().toStdString());
    newEmprunteur.setProfession(ui->professionText->toPlainText().toStdString());
    bool goodData = newEmprunteur.validate();
    if(goodData){
        bool executed;
        if(editing){
            newEmprunteur.setIdEmp(empInDialog->getIdEmp());
            executed = EmpDAO::update(newEmprunteur);
        }else{
            executed = EmpDAO::insert(newEmprunteur);
        }
        if(executed)
        {
            QMessageBox::information(this,"Emprunteur ajouté/modifié","Votre emprunteur a été ajouté/modifié avec succes");
            this->accept();
        }
        else{
            QMessageBox::warning(this,"Emprunteur non ajouté/modifié","Votre emprunteur n' a pas été ajouté/modifié, vérifiez votre data.");
        }
    }else
    {
        qDebug() << QString::fromStdString("Query Problem...");
    }
    //qDebug() << QString::fromStdString(newEmprunteur->toString());

}

bool AddEmpDialog::getEditing() const
{
    return editing;
}

void AddEmpDialog::setEditing(bool value)
{
    editing = value;
}

Emp *AddEmpDialog::getEmpInDialog() const
{
    return empInDialog;
}

void AddEmpDialog::setEmpInDialog(Emp *value)
{
    empInDialog = value;
}
