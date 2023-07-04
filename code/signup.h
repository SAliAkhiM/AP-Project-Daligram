#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>

#include"mainwindow.h"

#include"request.h"
#include"file.h"
#include"login1.h"
#include"message.h"

#include"listupdatethread.h"
#include"usermsgthread.h"

#include <QLineEdit>
#include <QPushButton>
#include<fstream>
#include<QDir>
#include<QMessageBox>
#include <QApplication>
#include <QCoreApplication>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>


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

    void on_pushButton_4_clicked();

    void on_checkBox_toggled(bool checked);

private:
    Ui::signUp *ui;
};

#endif // SIGNUP_H
