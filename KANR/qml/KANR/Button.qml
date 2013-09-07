import QtQuick 1.1

Image {
    id: button
    state: mouse.containsMouse ? "containsMouse" : "base state"
    width: 64
    height: 64
    source: "qrc:///res/start.png"

    signal click()
    MouseArea{
        id: mouse
        hoverEnabled: true
        anchors.fill: parent
        onClicked: click()
    }

    states:[
        State{
            name: "containsMouse"
            PropertyChanges{target: button; width : 84}
            PropertyChanges{target: button; height: 84}
        }
    ]

    transitions: [
        Transition {
            from: "base state"
            to: "containsMouse"
            NumberAnimation { target: button; properties: "width, height"; duration: 250}
        },
        Transition {
            from: "containsMouse"
            to: "base state"
            NumberAnimation { target: button; properties: "width, height"; duration: 250}
        }
    ]
}
