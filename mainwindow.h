#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <loading.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_runButton_clicked();
    void on_actionfollow_me_on_instagram_triggered();
    void on_actionExit_triggered();
    void showMain();

private:
    Ui::MainWindow *ui;
    Loading loading;
    void setup_ui();
    bool check_inputs();
    QDate date;
    QTime time;

};
#endif // MAINWINDOW_H
