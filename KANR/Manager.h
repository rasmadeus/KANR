#ifndef MANAGER_H
#define MANAGER_H

class PlotsData;
#include <QObject>
#include <QTimer>

class Manager : public QObject
{
typedef int ms;
    Q_OBJECT
public:
    Manager(PlotsData* data, QObject* root, QObject *parent = 0);
    ~Manager();
public slots:
    void setStep(ms step);
private slots:
    void start();
    void stop();
    void showValues();
private:
    void createConnections();
    void initObjects();
    QObject* findPlot(const QString& objectName) const;
private:
    PlotsData* data;
    QObject* root;
    QObject* menu;
    QObject* plots;
    QObject* arrayPlots[6];
    QTimer timer;
    ms step;
};

#endif // MANAGER_H
