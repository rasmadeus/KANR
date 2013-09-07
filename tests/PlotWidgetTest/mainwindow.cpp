#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QLayout>
#include "../../Plot/PlotWidget.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    plot = new PlotWidget(this);
    setCentralWidget(plot);
    connect(&timer, SIGNAL(timeout()), this, SLOT(cameNewValue()));
    timer.start(10);
    time = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

#include <qmath.h>
void MainWindow::cameNewValue()
{
    plot->cameNewValue(QPointF(time, qSin(M_PI * time)));
    time += 0.1;
}
