#ifndef PLOT_H
#define PLOT_H

class PlotWidget;
class QGraphicsProxyWidget;
#include <QDeclarativeItem>

class Plot : public QDeclarativeItem
{
    Q_PROPERTY(QColor gradientColor READ getGradientColor WRITE setGradientColor NOTIFY gradientColorChanged)
    Q_PROPERTY(QString curveTitle READ getCurveTitle WRITE setCurveTitle NOTIFY curveTitleChanged)
    Q_OBJECT
    Q_DISABLE_COPY(Plot)
public:
    Plot(QDeclarativeItem *parent = 0);
    ~Plot();
    const QColor& getGradientColor() const;
    void setGradientColor(const QColor& color);
    QString getCurveTitle() const;
    void setCurveTitle(const QString& title);
public slots:
    Q_INVOKABLE void cameNewValue(const QPointF& value);
signals:
    void gradientColorChanged();
    void curveTitleChanged();
    void wheel(int delta);
protected:
    void geometryChanged(const QRectF& newGeometry, const QRectF& oldGeometry);
    void wheelEvent(QGraphicsSceneWheelEvent* event);
private:
    PlotWidget* plot;
    QGraphicsProxyWidget* proxy;
    QColor gradientColor;
    QString curveTitle;
};

QML_DECLARE_TYPE(Plot)

#endif // PLOT_H

