#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbookdialog.h"
#include "addempdialog.h"
#include "empbookdialog.h"
#include "databaseconnector.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connectButtons();
    this->setDBConnectionStatus();
}

void MainWindow::connectButtons(){
    connect(ui->addBookButton,SIGNAL(clicked()),SLOT(addBookSlot()));
    connect(ui->addEmpButton,SIGNAL(clicked()),SLOT(addEmpSlot()));
    connect(ui->empBookButton,SIGNAL(clicked()),SLOT(empBookSlot()));
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

void MainWindow::addBookSlot()
{
    AddBookDialog *book;
    book = new AddBookDialog(this);
    book->setModal(true);
    book->show();
}

void MainWindow::addEmpSlot()
{
    AddEmpDialog *book;
    book = new AddEmpDialog(this);
    book->setModal(true);
    book->show();
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


