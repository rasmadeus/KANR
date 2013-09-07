#ifndef DATA_H
#define DATA_H

class QwtPlot;
#include <qwt_series_data.h>

class Data : public QwtSeriesData<QPointF>
{
public:
    void cameNewValue(const QPointF &value);
    size_t size() const;
    QPointF sample(size_t i) const;
    QRectF boundingRect() const;
    void setXmin(QwtPlot*  plot);
private:
    void insertNewValue(const QPointF& value);
    void calculateBoundingRectconst(const QPointF& value);
private:
    QRectF rect;
    QVector<QPointF> values;
};

#endif // DATA_H
