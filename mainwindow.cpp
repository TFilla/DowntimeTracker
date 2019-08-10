#include "mainwindow.h"
#include "ui_mainwindow.h"

int DIGITS = 2;
double ping_value = 0;
QString ip_address = "";


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
        qDebug() << "ADDRESS 1 ENABLED";
        get_ping(ip_address);
    }
    else {
        qDebug() << "ADDRESS 1 DISABLED";
    }
}

void MainWindow::on_address_editingFinished()
{
    qDebug() << "Address changed to "+ip_address;
    ip_address = ui->address->text();

}

void MainWindow::update_ping(double ping_value)
{
    QString new_ping;
    new_ping = QString::number(ping_value)+"ms";
    ui->ping->setText(new_ping);
}

void MainWindow::get_ping(QString ip_address)
{
    QProcess ping;
    ping.start("ping", QStringList() << "-n" << "1" << ip_address); // Only works for Windows
    ping.waitForFinished(-1);

    QString ping_stdout = ping.readAllStandardOutput();
    ping_stdout.chop(4);
    // qDebug() << ping_stdout;
    ping_stdout = ping_stdout.remove(QRegExp("[\\s\\S]*[^\\w+$]")); // Regex: [\s\S]*[^\w+$]
    QString ping_stderr = ping.readAllStandardError();
    qDebug() << "OUTPUT: "+ping_stdout;
    qDebug() << "ERROR: "+ping_stderr;
    ping_value = ping_stdout.toDouble();
    update_ping(ping_value);
    /*
    int exitCode = QProcess::execute("ping", QStringList() << "-n" << "1" << ip_address);
    if (0 == exitCode) {
        qDebug() << "it's alive";
    } else {
        qDebug() << "it's dead";
    }
    */
}
