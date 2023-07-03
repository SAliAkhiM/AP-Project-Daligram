#ifndef CREATEJOINCHANNELS_H
#define CREATEJOINCHANNELS_H

#include <QDialog>
#include "file.h"
#include "user.h"
#include "request.h"
namespace Ui {
class CreateJoinChannels;
}

class CreateJoinChannels : public QDialog
{
    Q_OBJECT

public:
    explicit CreateJoinChannels(QWidget *parent = nullptr);
    ~CreateJoinChannels();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreateJoinChannels *ui;
};

#endif // CREATEJOINCHANNELS_H
