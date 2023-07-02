#ifndef THREAD1_H
#define THREAD1_H

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
    void ListOperation(QString token);
signals:
   void changeSignal(QString);


private:
    Ui::thread1 *ui;
};

#endif // THREAD1_H
