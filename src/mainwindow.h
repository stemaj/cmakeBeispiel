#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include "ExampleLib.hpp"

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
    void on_actionAusf_hren_triggered();
    
private:
    QLabel *statusLabel;
    Ui::MainWindow *ui;

    ExampleLib l;
};

#endif // MAINWINDOW_H
