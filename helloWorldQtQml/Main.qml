import QtQuick

Window {
    id: root
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
    Rectangle{
        id: recBlack
        width: 300
        height: 300
        color: "black"
    }
    Rectangle{
        id: recYellow
        width: 300
        height: 300
        color: "yellow"
        x: 300
        Rectangle{
            id: recGreen
            width: 200
            height: 200
            color: "green"
            anchors.bottom: recYellow.bottom  // mỏ neo
            anchors.right: recYellow.right
        }
    }
}
