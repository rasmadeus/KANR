#include "plot.h"
#include <qdeclarative.h>

#include <QGraphicsProxyWidget>
#include "PlotWidget.h"
Plot::Plot(QDeclarativeItem *parent):
    QDeclarativeItem(parent)
{
    // By default, QDeclarativeItem does not draw anything. If you subclass
    // QDeclarativeItem to create a visual item, you will need to uncomment the
    // following line:

    setFlag(ItemHasNoContents, false);
    setFlags(ItemIsFocusable | ItemIsMovable | ItemIsSelectable);
    plot = new PlotWidget();
    proxy = new QGraphicsProxyWidget(this);
    proxy->setWidget(plot);
    setClip(true);
}

Plot::~Plot()
{
    delete plot;
}

const QColor& Plot::getGradientColor() const
{
    return gradientColor;
}

void Plot::setGradientColor(const QColor& color)
{
    gradientColor = color;
    plot->setGradient(color);
    emit gradientColorChanged();
}

QString Plot::getCurveTitle() const
{
    return curveTitle;
}

void Plot::setCurveTitle(const QString& title)
{
    curveTitle = title;
    plot->setCurveTitle(title);
    emit curveTitleChanged();
}

void Plot::cameNewValue(const QPointF& value)
{
    plot->cameNewValue(value);
}

void Plot::geometryChanged(const QRectF& newGeometry, const QRectF& oldGeometry)
{
    proxy->setGeometry(newGeometry);
    QDeclarativeItem::geometryChanged(newGeometry, oldGeometry);
}

#include <QGraphicsSceneWheelEvent>
void Plot::wheelEvent(QGraphicsSceneWheelEvent* event)
{
    emit wheel(event->delta() * 0.1);
}
