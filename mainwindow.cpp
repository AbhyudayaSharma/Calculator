#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QWidget>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Connect the exit button in the file menu
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
