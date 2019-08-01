#include "mainwindow.h"
#include "ui_mainwindow.h"

int DIGITS = 2;
double ping_value = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_boolping_stateChanged(int arg1)
{
    if (arg1 == 2) { // Checkbox returns 2 when enabled
        qDebug() << "IP SET 1 ENABLED";
    }
    else {
        qDebug() << "IP SET 1 DISABLED";
    }
}

void MainWindow::on_ip_editingFinished()
{
    qDebug() << "IP changed to "+ui->ip->text();
}

void MainWindow::update_ping(double ping_value)
{
    QString new_ping;
    new_ping = QString::number(ping_value)+"ms";
    ui->ping->setText(new_ping);
}
