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
    void start();

private slots:
    void onItemClicked (QListWidgetItem* item);
    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
