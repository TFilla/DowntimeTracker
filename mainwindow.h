#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QDebug>
#include <QString>
#include <QDate>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void on_boolping_stateChanged(int arg1);
    void on_ip_editingFinished();
    void update_ping(double ping_value);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
