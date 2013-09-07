#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

#include <QTimer>
class PlotWidget;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void cameNewValue();
private:
    Ui::MainWindow *ui;
    PlotWidget* plot;
    QTimer timer;
    double time;
};

#endif // MAINWINDOW_H
