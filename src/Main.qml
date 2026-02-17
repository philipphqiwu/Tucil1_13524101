import QtQuick
import QtQuick.Controls.Basic

ApplicationWindow {
    width: 1000
    height: 600
    visible: true
    title: qsTr("Queens")

    background: Rectangle {
        color: Colors.currentTheme.background
    }

    ApplicationFlow {
        width: parent.width
        height: parent.height
    }
}
