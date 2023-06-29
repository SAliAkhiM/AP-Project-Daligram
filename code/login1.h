#ifndef LOGIN1_H
#define LOGIN1_H

#include <QDialog>

namespace Ui {
class login1;
}

class login1 : public QDialog
{
    Q_OBJECT

public:
    explicit login1(QWidget *parent = nullptr);
    ~login1();

private slots:
    void on_logIn_pushButton_clicked();

    void on_checkBox_toggled(bool checked);

private:
    Ui::login1 *ui;
};

#endif // LOGIN1_H
