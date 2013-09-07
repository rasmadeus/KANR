#include "Manager.h"

Manager::Manager(PlotsData *data, QObject *root, QObject *parent) :
    QObject(parent),
    data(data),
    root(root),
    menu(0),
    step(10)
{
    initObjects();
    createConnections();
}

#include "PlotsData.h"
Manager::~Manager()
{
    delete data;
}

void Manager::setStep(ms step)
{
    bool timerIsActive = timer.isActive();

    if(timerIsActive){
        stop();
    }

    this->step = step;

    if(timerIsActive){
        start();
    }
}

void Manager::start()
{
    timer.start(step);
}

void Manager::stop()
{
    timer.stop();
}

void Manager::showValues()
{
    QMetaObject::invokeMethod(arrayPlots[0], "cameNewValue", Q_ARG(QPointF, data->value(0)));
    QMetaObject::invokeMethod(arrayPlots[1], "cameNewValue", Q_ARG(QPointF, data->value(1)));
    QMetaObject::invokeMethod(arrayPlots[2], "cameNewValue", Q_ARG(QPointF, data->value(2)));
    QMetaObject::invokeMethod(arrayPlots[3], "cameNewValue", Q_ARG(QPointF, data->value(3)));
    QMetaObject::invokeMethod(arrayPlots[4], "cameNewValue", Q_ARG(QPointF, data->value(4)));
    QMetaObject::invokeMethod(arrayPlots[5], "cameNewValue", Q_ARG(QPointF, data->value(5)));
}

void Manager::createConnections()
{
    if(menu){
        QObject::connect(menu, SIGNAL(startShow()), this, SLOT(start()));
        QObject::connect(menu, SIGNAL(stopShow()), this, SLOT(stop()));
    }
    connect(&timer, SIGNAL(timeout()), this, SLOT(showValues()));
}

void Manager::initObjects()
{
    if(!root){
        return;
    }
    QObject* area = root->findChild<QObject*>("area");
    if(area){
        menu = area->findChild<QObject*>("menu");
        plots = area->findChild<QObject*>("plots");
        if(plots){
            arrayPlots[0] = findPlot("plot1");
            arrayPlots[1] = findPlot("plot2");
            arrayPlots[2] = findPlot("plot3");
            arrayPlots[3] = findPlot("plot4");
            arrayPlots[4] = findPlot("plot5");
            arrayPlots[5] = findPlot("plot6");
        }
    }
}

QObject* Manager::findPlot(const QString& objectName) const
{
    return plots->findChild<QObject*>(objectName)->findChild<QObject*>("plot");
}
