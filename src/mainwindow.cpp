#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    statusLabel(new QLabel("")),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    statusBar()->addWidget(statusLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAusf_hren_triggered()
{
    statusLabel->setText(QString::fromStdString(l.gibFuenf()));
}
