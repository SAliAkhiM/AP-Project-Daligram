#ifndef THREAD1_H
#define THREAD1_H
#include"mainwindow.h"
#include <QThread>
#include <QDialog>


namespace Ui {
class thread1;
}

class thread1 : public QDialog
{
    Q_OBJECT

public:
    explicit thread1(QWidget *parent = nullptr);
    ~thread1();
    void ListOperation(QString token,MainWindow* m);
    void usrMsgUpdate(QString token,MainWindow* m);
    void groupMsgUpdate(QString token,MainWindow* m);
    void channelMsgUpdate(QString token,MainWindow* m);

signals:
   void listChangeSignal(QString);
   void changeSignal(QString);


private:
    Ui::thread1 *ui;
};

#endif // THREAD1_H
