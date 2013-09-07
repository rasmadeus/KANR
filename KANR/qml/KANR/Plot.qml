import QtQuick 1.1
import rra.kanr 1.0

Rectangle{
    property color gradienColorEnd: "#A5C1E4"
    property bool isControlPressed: false
    property string titleOfCurve: "Test curve"

    function resizePlot(delta)
    {
        if(delta < 0 && base.width <= 200){
            return
        }
        base.width  += delta
        base.height += delta
    }

    function rotatePlot(delta)
    {
        base.rotation += 0.1 * delta
    }


    function resize(width, height){
        base.width = width
        base.height = height
    }

    function move(x, y){
        base.x = x
        base.y = y
    }

    id: base
    width: 300
    height: 300
    border.width: 1
    opacity: mouse.containsMouse ? 0.5 : 1
    radius: 10
    gradient: Gradient {
        GradientStop {
            position: 0
            color: "#ffffff"
        }
        GradientStop {
            position: 1
            color: gradienColorEnd
        }
    }

    Rectangle {
        x: 4
        y: 4
        width: parent.width - 8
        height: parent.height - 8
        anchors.centerIn: parent
        Plot{
            id: plot
            objectName: "plot"
            width: parent.width
            height: parent.width
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            gradientColor: gradienColorEnd            
            curveTitle: titleOfCurve
            Keys.onPressed:{                
                if(event.key == Qt.Key_Control){
                    isControlPressed = !isControlPressed                    
                }
            }

            onWheel: isControlPressed ? rotatePlot(delta) : resizePlot(delta)

        }
    }

    MouseArea{
        id: mouse
        anchors.fill: parent
        drag.target: parent
    }
}
