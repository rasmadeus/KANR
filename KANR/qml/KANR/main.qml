import QtQuick 1.1

Rectangle {
    objectName: "base"
    id: base
    width: 500
    height: 500
    color: "#444"
    Row{
        objectName: "area"
        id: area
        Menu{
            objectName: "menu"
            id: menu
            width: 84
            onTileClick: plots.tile()
        }
        PlotsArea{
            objectName: "plots"
            id: plots
            color: base.color
            width: base.width - 84
            height: base.height
            onHeightChanged: tile()
            onWidthChanged: tile()
        }
    }

    Component.onCompleted: plots.tile()
}
