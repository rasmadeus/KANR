#include <QApplication>
#include "mainwindow.h"
int main(int argc, char *argv[])
{
    QApplication PlotWidgetTest(argc, argv);
        MainWindow mw;
        mw.show();
    return PlotWidgetTest.exec();
}
