import QtQuick 1.1
import rra.kanr 1.0

Rectangle {
    width: 600
    height: 600

    Rectangle{
        width: 0.9 * parent.width
        height: 0.9 * parent.height
        anchors.centerIn: parent
        border.width: 2
        radius: 30

        Plot{
            curveTitle: "Hy there"
            gradientColor: "#f00"
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right

        }
    }


}
