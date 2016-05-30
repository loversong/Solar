#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include "mywidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void start();
    void pause();
    void stop();
    void exit();
    void run();
    void move();
    void slideChange();
protected:
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int date;
    QString tdate;
};

#endif // MAINWINDOW_H
