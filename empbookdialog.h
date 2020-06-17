#ifndef EMPBOOKDIALOG_H
#define EMPBOOKDIALOG_H

#include <QDialog>

namespace Ui {
class EmpBookDialog;
}

class EmpBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EmpBookDialog(QWidget *parent = nullptr);
    ~EmpBookDialog();

private:
    Ui::EmpBookDialog *ui;
};

#endif // EMPBOOKDIALOG_H
