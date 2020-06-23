#include "addbookdialog.h"
#include "ui_addbookdialog.h"
#include <QtDebug>
#include <QMessageBox>

AddBookDialog::AddBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
    ui->copyEdit->setValidator( new QIntValidator(1, 100, this) );
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

void AddBookDialog::on_anuuler_clicked()
{
    this->close();
}

void AddBookDialog::on_Okb_clicked()
{
    Book newBook;
    newBook.setTitle(ui->titleText->toPlainText().toStdString());
    newBook.setResume(ui->resumeEdit->toPlainText().toStdString());
    newBook.setEntryDate(ui->dateEdit->text().toStdString());
    QStringList authors;
    for (int index = 0; index < ui->authorsBox->count(); index++)
        authors << ui->authorsBox->itemText(index);
    newBook.setAuthors(authors);
    QStringList tags;
    for (int index = 0; index < ui->tagsBox->count(); index++)
        tags << ui->tagsBox->itemText(index);
    newBook.setTags(tags);
    newBook.setNumberCopies(ui->copyEdit->text().toInt());
qDebug() << QString::fromStdString(newBook.toString());
    bool goodData = newBook.validate();
    if(goodData){
        bool executed;
//        if(editing){
//            newBook.setIdEmp(bookInDialog->getIdEmp());
//            executed = BookDAO::update(newBook);
//        }else{
            executed = BookDAO::insert(newBook);
//        }
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
    //qDebug() << QString::fromStdString(newBook->toString());
}
