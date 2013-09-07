# Add more folders to ship with the application, here
folder_01.source = qml/TestKANR
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
# CONFIG += mobility
# MOBILITY +=

# Speed up launching on MeeGo/Harmattan when using applauncherd daemon
# CONFIG += qdeclarative-boostable

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    ../../KANR/PlotsData.cpp \
    ../../KANR/Manager.cpp \
    ../../Plot/Data.cpp \
    ../../Plot/PlotWidget.cpp

# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qmlapplicationviewer/qmlapplicationviewer.pri)
qtcAddDeployment()

include ("/home/rasmadeus/Programs/Qt/qwt-6.1.0/features/qwt.prf")

HEADERS += \
    ../../KANR/PlotsData.h \
    ../../KANR/Manager.h \
    ../../Plot/Data.h \
    ../../Plot/PlotWidget.h

OTHER_FILES += \
    ../../KANR/qml/KANR/PlotsArea.qml \
    ../../KANR/qml/KANR/Plot.qml \
    ../../KANR/qml/KANR/Menu.qml \
    ../../KANR/qml/KANR/main.qml \
    ../../KANR/qml/KANR/Button.qml

RESOURCES += \
    ../../KANR/res.qrc
