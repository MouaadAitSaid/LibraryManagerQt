#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbookdialog.h"
#include "empbookdialog.h"
#include "databaseconnector.h"
#include "empdao.h"

#include <QAbstractItemView>
#include <QMessageBox>






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    empTable = new QTableWidget(0,6,ui->Tab_people);
    empTable->setGeometry(QRect(10, 50, 721, 421));
    empTable->setObjectName(QString::fromUtf8("empTable"));
    empTable->setStyleSheet(QString::fromUtf8("background-color: white"));
    empTable->horizontalHeader()->setStretchLastSection(true);
    empTable->verticalHeader()->setVisible(false);
    empTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    empTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->connectButtons();
    this->setDBConnectionStatus();
    this->initiateEmpTable("");
}

void MainWindow::connectButtons(){
    connect(ui->addBookButton,SIGNAL(clicked()),SLOT(addBookSlot()));
    connect(ui->addEmpButton,SIGNAL(clicked()),SLOT(addEmpSlot()));
    connect(ui->empBookButton,SIGNAL(clicked()),SLOT(empBookSlot()));
    connect(empTable->selectionModel()
            , SIGNAL(currentRowChanged(QModelIndex,QModelIndex))
            , SLOT(tableRowChenged(QModelIndex)));
}

void MainWindow::setDBConnectionStatus(){
    DatabaseConnector::connect();
    bool connectedDB = DatabaseConnector::testConn();
    if (connectedDB){
        ui->connTestLabel->setText("    Base de données connecté avec succes :D .   ");
        ui->connTestLabel->setStyleSheet("QLabel { background-color : green; color: white; }");
    }else{
        ui->connTestLabel->setText("    Base de données non connecté :( .   ");
        ui->connTestLabel->setStyleSheet("QLabel { background-color : red; color: white; }");
    }
    ui->connTestLabel->setAlignment(Qt::AlignCenter);
}

void MainWindow::fillEmpTable(QList<Emp *> emprunteurs)
{
    std::string log = "Heeeeeeeeeeere"+ std::to_string(emprunteurs.size());
    qDebug() << QString::fromStdString(log);
    empTable->setRowCount(0);
    std::string logh = "Ha hya texecutat hna"+ std::to_string(emprunteurs.size());

    qDebug() << QString::fromStdString(logh);
    empTable->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    empTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Prénom"));
    empTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Nom"));
    empTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Adresse"));
    empTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Date de naissance"));
    empTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Profession"));


    for( int row = 0; row < emprunteurs.size(); row++ )
    {
        qDebug() << QString::number(row);
        empTable->insertRow(row);
        empTable->setItem(row,0,new QTableWidgetItem(QString::number(emprunteurs[row]->getIdEmp())));
        empTable->setItem(row,1,new QTableWidgetItem(QString::fromStdString(emprunteurs[row]->getFName())));
        empTable->setItem(row,2,new QTableWidgetItem(QString::fromStdString(emprunteurs[row]->getLName())));
        empTable->setItem(row,3,new QTableWidgetItem(QString::fromStdString(emprunteurs[row]->getAdress())));
        empTable->setItem(row,4,new QTableWidgetItem(QString::fromStdString(emprunteurs[row]->getBirthDate())));
        empTable->setItem(row,5,new QTableWidgetItem(QString::fromStdString(emprunteurs[row]->getProfession())));
    }

}

void MainWindow::initiateEmpTable(std::string searchText)
{
    empTable->clearSelection();
    QList<Emp *> initialEmps = EmpDAO::getAll(searchText);
    this->fillEmpTable(initialEmps);
}

void MainWindow::addBookSlot()
{
    AddBookDialog *book;
    book = new AddBookDialog(this);
    book->setModal(true);
    book->exec();
}

void MainWindow::addEmpSlot()
{
    AddEmpDialog *empDialog;
    empDialog = new AddEmpDialog(this);
    empDialog->setModal(true);
    int result = empDialog->exec();
    if(result==QDialog::Accepted)
    {
        this->initiateEmpTable("");
    }
}

void MainWindow::empBookSlot()
{
    EmpBookDialog *book;
    book = new EmpBookDialog(this);
    book->setModal(true);
    book->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_empSearchArea_returnPressed()
{
    this->initiateEmpTable(ui->empSearchArea->text().toStdString());
}



void MainWindow::tableRowChenged(const QModelIndex &index)
{
    qDebug() << QString::fromStdString(std::to_string(index.row())+"HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH");
    if(index.row()!=-1){
        const int row = index.row();
        selectedEmp = new Emp();
        selectedEmp->setIdEmp(empTable->item(row,0)->text().toInt());
        selectedEmp->setFName(empTable->item(row,1)->text().toStdString());
        selectedEmp->setLName(empTable->item(row,2)->text().toStdString());
        selectedEmp->setAdress(empTable->item(row,3)->text().toStdString());
        selectedEmp->setBirthDate(empTable->item(row,4)->text().toStdString());
        selectedEmp->setProfession(empTable->item(row,5)->text().toStdString());
        qDebug() << QString::fromStdString("Object Emp : "+selectedEmp->toString());
        qDebug() << QString::fromStdString("Object Emp : ");
    }else{
        selectedEmp = nullptr;
    }

}

void MainWindow::on_editEmpButton_clicked()
{
    if(selectedEmp!=nullptr){
        AddEmpDialog *empDialog;
        empDialog = new AddEmpDialog(this,true,selectedEmp);
        empDialog->setModal(true);

        qDebug()<< QString::fromStdString(empDialog->getEmpInDialog()->toString());

        int result = empDialog->exec();
        if(result==QDialog::Accepted)
        {
            this->initiateEmpTable("");
        }}
    else{
        QMessageBox::warning(this,"Attention","Veuillez selectionner un emprunteur d'abord.");
    }
}

void MainWindow::on_delEmpButton_clicked()
{
    if(selectedEmp!=nullptr){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Confirmation", "Vous confirmer vouloir supprimer cet empreinteur?",
                                      QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            EmpDAO::remove(selectedEmp->getIdEmp());
            QMessageBox::information(this,"Suppression réussite","Votre emprunteur est supprimé avec succes.");
            this->initiateEmpTable("");
        }
    }
    else{
        QMessageBox::warning(this,"Attention","Veuillez selectionner un emprunteur d'abord.");
    }

}
