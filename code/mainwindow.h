#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QtWidgets>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startUserList();
    void startGroupList();
    void startChannelList();

private slots:
    void onItemClicked (QListWidgetItem* item);


    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
