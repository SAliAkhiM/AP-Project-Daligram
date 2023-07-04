#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets>
#include <QMainWindow>
#include<QString>
#include<fstream>
#include"file.h"
#include"message.h"
#include"request.h"
#include<QMessageBox>
#include<vector>
#include "createjoinchannels.h"
#include "createjoingroups.h"
#include "newuserchats.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    int UserIsLogin;
    QString userToken;
    QString userUserName;
    QString userPassword;
    QString curdst;
    QString dstType;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startUserList();
    void startGroupList();
    void startChannelList();

    void setUserToken(QString);
    void setDstType(QString);
    void setCurDst(QString);
    void setUserIsLogin(int);
    void setUserUserName(QString);
    void setUserPassword(QString);
    QString getUserToken();
    QString getDstType();
    QString getCurDst();
    QString getUserUserName();
    QString getUserPassword();
    int getUserIsLogin();
    void readProfile();

    void listChange2();
    void userMsgChange(QString user);
    void groupMsgChange(QString user);
    void channelMsgChange(QString user);


public slots:

    void Slot(QString);
    void userMsgChangeSlot(QString);
    void groupMsgChangeSlot(QString);
    void channelMsgChangeSlot(QString);



    void onItemClicked (QListWidgetItem* item);



private slots:

    void on_sendButton1_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_UsersSearch_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
