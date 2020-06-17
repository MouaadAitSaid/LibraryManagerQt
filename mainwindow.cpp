#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbookdialog.h"
#include "addempdialog.h"
#include "empbookdialog.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connectButtons();
}

void MainWindow::connectButtons(){
    connect(ui->addBookButton,SIGNAL(clicked()),SLOT(addBookSlot()));
    connect(ui->addEmpButton,SIGNAL(clicked()),SLOT(addEmpSlot()));
    connect(ui->empBookButton,SIGNAL(clicked()),SLOT(empBookSlot()));
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

