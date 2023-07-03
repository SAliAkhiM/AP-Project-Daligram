#ifndef CREATEJOINGROUPS_H
#define CREATEJOINGROUPS_H
#include "file.h"
#include "request.h"
#include "user.h"

#include <QDialog>

namespace Ui {
class CreateJoinGroups;
}

class CreateJoinGroups : public QDialog
{
    Q_OBJECT

public:
    explicit CreateJoinGroups(QWidget *parent = nullptr);
    ~CreateJoinGroups();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::CreateJoinGroups *ui;
};

#endif // CREATEJOINGROUPS_H
