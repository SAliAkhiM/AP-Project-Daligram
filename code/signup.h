#ifndef SIGNUP_H
#define SIGNUP_H

#include"request.h"
#include <QDialog>

namespace Ui {
class signUp;
}

class signUp : public QDialog
{
    Q_OBJECT

public:
    explicit signUp(QWidget *parent = nullptr);
    ~signUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::signUp *ui;
};

#endif // SIGNUP_H
