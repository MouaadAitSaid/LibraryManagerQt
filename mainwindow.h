#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "emp.h"
#include "addempdialog.h"
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

    QTableWidget *empTable;
    Emp *selectedEmp = nullptr;



private slots:
    void addBookSlot();
    void addEmpSlot();
    void empBookSlot();
    void initiateEmpTable(std::string searchText);

    void on_empSearchArea_returnPressed();

    void tableRowChenged(const QModelIndex &index);

    void on_editEmpButton_clicked();

    void on_delEmpButton_clicked();

private:
    Ui::MainWindow *ui;
    void connectButtons();
    void setDBConnectionStatus();
    void fillEmpTable(QList<Emp *> emprunteurs);

};
#endif // MAINWINDOW_H
