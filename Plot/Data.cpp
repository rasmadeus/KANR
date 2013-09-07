#include "Data.h"

void Data::cameNewValue(const QPointF& value)
{
    insertNewValue(value);
    calculateBoundingRectconst(value);
}

size_t Data::size() const
{
    return values.size();
}

QPointF Data::sample(size_t i) const
{
    return values[i];
}

#include <qwt_plot.h>
void Data::setXmin(QwtPlot* plot)
{
    plot->setAxisScale(QwtPlot::xBottom, values.first().x(), values.last().x());
}

QRectF Data::boundingRect() const
{
    return rect;
}

void Data::insertNewValue(const QPointF& value)
{
    if(values.size() > 250){
        values.removeFirst();
    }
    values.push_back(value);
}

void Data::calculateBoundingRectconst(const QPointF& value)
{

    if (rect.width() < 0 || rect.height() < 0){
        rect.setRect(value.x(), value.y(), 0.0, 0.0);
    }
    else{
        rect.setRight(value.x());
        if (value.y() > rect.bottom()){
            rect.setBottom(value.y());
        }
        if (value.y() < rect.top()){
            rect.setTop(value.y());
        }
    }
}
