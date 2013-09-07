#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

class Data;
class QwtPlotCurve;
#include <qwt_plot.h>


class PlotWidget : public QwtPlot
{
    Q_OBJECT
public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();
    void setGradient(const QColor& color);
    void cameNewValue(const QPointF& value);
    void setCurveTitle(const QString& title);
    QString getCurveTitle() const;
private:
    void setLookAndFeel();
    void setLookAndFeelFrame();
    void createCanvas();
    void createGrid();
    void createLegend();
    void createCurve();
private:
    QwtPlotCurve* curve;
    Data* data;
};

#endif // PLOTWIDGET_H
