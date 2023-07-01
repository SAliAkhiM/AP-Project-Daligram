#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets>
#include <QMainWindow>
#include<QString>
#include<fstream>

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


private slots:
    void onItemClicked (QListWidgetItem* item);





    void on_sendButton1_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
