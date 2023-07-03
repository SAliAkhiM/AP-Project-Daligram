#ifndef NEWUSERCHATS_H
#define NEWUSERCHATS_H

#include <QDialog>
#include "file.h"
#include "request.h"
#include "user.h"
namespace Ui {
class newUserChats;
}

class newUserChats : public QDialog
{
    Q_OBJECT

public:
    explicit newUserChats(QWidget *parent = nullptr);
    ~newUserChats();

private slots:
    void on_pushButton_clicked();

private:
    Ui::newUserChats *ui;
};

#endif // NEWUSERCHATS_H
