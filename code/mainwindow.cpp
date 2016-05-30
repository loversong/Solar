#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "planet.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);

    timer = new QTimer;

    QStringList velLevel;
    velLevel << "Slow" << "Medium" << "Fast";
    ui->comboBox->addItems(velLevel);

    QStringList changes;
    changes << "Sun double" << "Sun reset" << "Sun halve"
            << "Earth double" << "Earth reset" << "Earth halve"
            << "Big collision" << "Small collision";
    ui->changeCombo->addItems(changes);

    ui->horizontalSlider->setMaximum(89);
    ui->horizontalSlider->setMinimum(-89);
    ui->horizontalSlider->setValue(0);
    ui->verticalSlider->setMaximum(89);
    ui->verticalSlider->setMinimum(-89);
    ui->verticalSlider->setValue(30);

    connect(ui->startButton, SIGNAL(clicked(bool)), this, SLOT(start()));
    connect(ui->pauseButton, SIGNAL(clicked(bool)), this, SLOT(pause()));
    connect(ui->stopButton, SIGNAL(clicked(bool)), this, SLOT(stop()));
    connect(ui->exitButton, SIGNAL(clicked(bool)), this, SLOT(exit()));
    connect(ui->runButton, SIGNAL(clicked(bool)), this, SLOT(run()));
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), this, SLOT(slideChange()));
    connect(ui->verticalSlider, SIGNAL(sliderMoved(int)), this, SLOT(slideChange()));
    timer->stop();
    date = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start()
{
    ui->startButton->setEnabled(false);
    ui->pauseButton->setEnabled(true);
    ui->stopButton->setEnabled(true);
    switch (ui->comboBox->currentIndex()) {
    case 0:
        timer->start(100);
        break;
    case 1:
        timer->start(10);
        break;
    case 2:
        timer->start(0.1);
        break;
    default:
        break;
    }
}

void MainWindow::pause()
{
    ui->startButton->setText(tr("Resume"));
    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    timer->stop();
}

void MainWindow::stop()
{
    ui->startButton->setText(tr("Start"));
    ui->startButton->setEnabled(true);
    ui->pauseButton->setEnabled(false);
    ui->stopButton->setEnabled(false);
    ui->openGLWidget->reset();
    date = 0;
    ui->dateLabel->setText("0");
    timer->stop();
}

void MainWindow::exit()
{
    this->close();
}

void MainWindow::run()
{
    ui->openGLWidget->eventChange(ui->changeCombo->currentIndex());
}

void MainWindow::move()
{
    date++;
    tdate.setNum(date);

    ui->dateLabel->setText(tdate);
    ui->openGLWidget->planetMove();
    int i, j;
    if (ui->openGLWidget->isCollide(i, j))
    {
        std::string colText;
        colText = starName[i] + " and " + starName[j] + " had been collided!";
        QString qText = QString::fromStdString(colText);
        QMessageBox::information(NULL, tr("Warning"), qText, QMessageBox::Warning, QMessageBox::Ok);
        stop();
    }
    if (ui->openGLWidget->isOut(i))
    {
        std::string colText;
        colText = starName[i] + " had been flied out!";
        QString qText = QString::fromStdString(colText);
        QMessageBox::information(NULL, tr("Warning"), qText, QMessageBox::Warning, QMessageBox::Ok);
        stop();
    }
}

void MainWindow::slideChange()
{
    ui->openGLWidget->setAngle(ui->horizontalSlider->value(), ui->verticalSlider->value());
}
