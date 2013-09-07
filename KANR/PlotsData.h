#ifndef PLOTSDATA_H
#define PLOTSDATA_H

#include <QPointF>
#include <QVariant>

class PlotsData
{
public:
    virtual ~PlotsData();
    QPointF value(int i);
protected:
    virtual QPointF getValue(int i) = 0;
};

#endif // PLOTSDATA_H
