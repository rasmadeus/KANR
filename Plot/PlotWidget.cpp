#include "PlotWidget.h"

PlotWidget::PlotWidget(QWidget *parent) :
    QwtPlot(parent),
    curve(0)
{
    setLookAndFeel();
}

#include "Data.h"
PlotWidget::~PlotWidget()
{
    delete data;
}

void PlotWidget::setGradient(const QColor& color)
{
    QPalette pal(color);
    const QColor buttonColor = pal.color( QPalette::Button );
    QLinearGradient gradient( rect().topLeft(), rect().bottomLeft() );
    gradient.setColorAt( 0.00, Qt::white );
    gradient.setColorAt( 1.00, buttonColor );
    pal.setBrush( QPalette::Window, gradient );
    setPalette(pal);
}

void PlotWidget::cameNewValue(const QPointF &value)
{
    data->cameNewValue(value);
    data->setXmin(this);
    replot();
}

#include <qwt_plot_curve.h>
void PlotWidget::setCurveTitle(const QString& title)
{
    curve->setTitle(title);
    updateLegend();
}

QString PlotWidget::getCurveTitle() const
{
    return curve->title().text();
}

void PlotWidget::setLookAndFeel()
{
    setLookAndFeelFrame();
    createCanvas();
    createGrid();
    createLegend();
    createCurve();
}

void PlotWidget::setLookAndFeelFrame()
{
    setAutoFillBackground(true);
    QFont small;
    small.setPointSize(8);
    setAxisFont(xBottom, small);
    setAxisFont(yLeft, small);
}

#include <qwt_plot_canvas.h>
void PlotWidget::createCanvas()
{
    QwtPlotCanvas* canvas = new QwtPlotCanvas();
    canvas->setLineWidth(1);
    canvas->setFrameStyle(QFrame::Box | QFrame::Plain);
    canvas->setBorderRadius(10);
    QPalette canvasPalette(Qt::white);
    canvasPalette.setColor(QPalette::Foreground, Qt::lightGray);
    canvas->setPalette(canvasPalette);
    setCanvas(canvas);
}

#include <qwt_plot_grid.h>
void PlotWidget::createGrid()
{
    QwtPlotGrid* grid = new QwtPlotGrid();
    grid->setMajorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->setMinorPen(QPen(Qt::gray, 0, Qt::DotLine));
    grid->attach(this);    
}

#include <qwt_legend.h>
void PlotWidget::createLegend()
{
    insertLegend(new QwtLegend(this), TopLegend);
}

void PlotWidget::createCurve()
{
    curve = new QwtPlotCurve();
    curve->setStyle(QwtPlotCurve::Lines);
    curve->setPen(QPen(QBrush(Qt::red), 1));
    curve->setRenderHint(QwtPlotItem::RenderAntialiased, true);
    curve->setPaintAttribute(QwtPlotCurve::ClipPolygons, false);
    data = new Data();
    curve->setSamples(data);
    curve->attach(this);    
}
