import QtQuick 1.1

Rectangle {

    id: base
    width: 500
    height: 500
    property int space: 2

    function resize(width, height)
    {
        plot1.resize(width, height)
        plot2.resize(width, height)
        plot3.resize(width, height)
        plot4.resize(width, height)
        plot5.resize(width, height)
        plot6.resize(width, height)
    }

    function move()
    {
        plot1.move(space, space)

        var xFirstColumn  = plot1.x
        var xSecondColumn = plot1.x +plot1.width + space;
        var yFirstRow = plot1.y
        var ySecondRow = plot1.height + plot1.y + space;
        var yThirdRow = ySecondRow + plot3.height + space;

        plot2.move(xSecondColumn, yFirstRow)
        plot3.move(xFirstColumn, ySecondRow)
        plot4.move(xSecondColumn, ySecondRow)
        plot5.move(xFirstColumn, yThirdRow)
        plot6.move(xSecondColumn, yThirdRow)
    }

    function tile()
    {
        resize(base.width / 2 - 1.5*space, base.height / 3 - 1.5*space)
        move()
    }

    Plot{
        id: plot1
        objectName: "plot1"
        gradienColorEnd: "#888"
        titleOfCurve: "Yaw"
    }
    Plot{
        id: plot2
        objectName: "plot2"
        gradienColorEnd: "#888"
        titleOfCurve: "Yaw trajectory"
    }
    Plot{
        id: plot3
        objectName: "plot3"
        gradienColorEnd: "#888"
        titleOfCurve: "Pitch"
    }
    Plot{
        id: plot4
        objectName: "plot4"
        gradienColorEnd: "#888"
        titleOfCurve: "Pitch trajectory"
    }
    Plot{
        id: plot5
        objectName: "plot5"
        gradienColorEnd: "#888"
        titleOfCurve: "Roll"
    }
    Plot{
        id: plot6
        objectName: "plot6"
        gradienColorEnd: "#888"
        titleOfCurve: "Roll trajectory"
    }

}
