#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "addempdialog.h"
#include "addbookdialog.h"
#include <QTableWidget>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    /**** EmpLogic  **********************************************************************/
public :
    QTableWidget *empTable;
    Emp *selectedEmp = nullptr;
private:
    void fillEmpTable(QList<Emp *> emprunteurs);
private slots:
    void addEmpSlot();

    void initiateEmpTable(std::string searchText);

    void on_empSearchArea_returnPressed();

    void tableEmpRowChenged(const QModelIndex &index);

    void on_editEmpButton_clicked();

    void on_delEmpButton_clicked();

    /**** end  EmpLogic  **********************************************************************/
    /**** BookLogic  **********************************************************************/
public:
    QTableWidget *bookTable;
    Book *selectedBook = nullptr;
private:
    void fillBookTable(QList<Book *> books);
private slots:
    void addBookSlot();
    void initiateBookTable(std::string searchText);

    void on_bookSearchArea_returnPressed();

    void tableBookRowChenged(const QModelIndex &index);

    void on_editBookButton_clicked();

    void on_delBookButton_clicked();
    /**** End BookLogic  **********************************************************************/




private:
    Ui::MainWindow *ui;
    void connectButtons();
    void setDBConnectionStatus();



private slots:
    void empBookSlot();

};
#endif // MAINWINDOW_H
