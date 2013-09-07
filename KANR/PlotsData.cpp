#include "PlotsData.h"

PlotsData::~PlotsData()
{
}

QPointF PlotsData::value(int i)
{
    if(i < 0 || i > 5){
        return QPointF();
    }
    return getValue(i);
}
