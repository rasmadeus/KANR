import QtQuick 1.1

Column{
    spacing: 4
    signal tileClick();
    signal startShow();
    signal stopShow();
    Button{
        id: start
        source: "qrc:///res/start.png"
        onClick: startShow()
    }
    Button{
        id: stop
        source: "qrc:///res/stop.png"
        onClick: stopShow()
    }
    Button{
        id: tile
        source: "qrc:///res/home.png"
        onClick: tileClick()
    }
    Button{
        id: exit
        source: "qrc:///res/exit.png"
        onClick: Qt.quit()
    }
}
