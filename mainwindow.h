#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBookSlot();
    void addEmpSlot();
    void empBookSlot();

private:
    Ui::MainWindow *ui;
    void connectButtons();
};
#endif // MAINWINDOW_H