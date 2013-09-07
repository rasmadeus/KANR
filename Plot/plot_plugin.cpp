#include "plot_plugin.h"
#include "plot.h"

#include <qdeclarative.h>

void PlotPlugin::registerTypes(const char *uri)
{
    // @uri rra.kanr
    qmlRegisterType<Plot>(uri, 1, 0, "Plot");
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(Plot, PlotPlugin)
#endif

