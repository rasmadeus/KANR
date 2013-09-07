#include <QApplication>
#include "qmlapplicationviewer.h"

#include "../../KANR/PlotsData.h"
#include "../../KANR/Manager.h"

#include <qmath.h>
class Sinus: public PlotsData
{
public:
    Sinus()
    {
        step = -0.1;
    }
protected:
    QPointF getValue(int i)
    {
        if(!i){
            step += 0.1;
        }
        return QPointF(step, qSin(M_PI * step));
    }
private:
    double step;
};

#include <QGraphicsObject>
Q_DECL_EXPORT int main(int argc, char *argv[])
{
    QScopedPointer<QApplication> app(createApplication(argc, argv));

    QmlApplicationViewer viewer;
    viewer.addImportPath(QLatin1String("modules"));
    viewer.setOrientation(QmlApplicationViewer::ScreenOrientationAuto);
    viewer.setMainQmlFile(QLatin1String("../../KANR/qml/KANR/main.qml"));
    viewer.showExpanded();

    Manager manager(new Sinus(), viewer.rootObject());

    return app->exec();
}
