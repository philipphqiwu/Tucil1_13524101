import QtQuick
import QtQuick.Layouts

Item {
    id: home
    property alias getStartedbutton: getStartedButton
    property alias grid: grid
    property alias header: header
    property alias caption: caption

    states: [
        State {
            name: "landscape"
            PropertyChanges {
                target: grid
                anchors.topMargin: 0
            }
            PropertyChanges {
                target: header
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: getStartedButton
                Layout.preferredWidth: home.width / 4
                Layout.preferredHeight: home.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: getStartedButton
                Layout.minimumHeight: 0
            }
        }
    ]

    GridLayout {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: home.top
        flow: GridLayout.TopToBottom
        Image {
            id: image
            Layout.preferredHeight: home.height / 3
            Layout.preferredWidth: home.height / 3
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.margins: 5
            source: "./Resources/images/boards/home.png"
        }
        Text {
            id: header
            text: qsTr("Queens Solver")
            font.pixelSize: 32
            font.weight: 700
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
        }
        Text {
            id: caption
            text: qsTr(" might help you land a job \n in FAANG (?)")
            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            Layout.maximumWidth: home.width
            wrapMode: Text.Wrap
            font.weight: 400
            color: Colors.currentTheme.caption
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
        }
        CustomButton {
            id: getStartedButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.minimumWidth: 150
            Layout.minimumHeight: 40
            buttonText: "Get Started"
        }
    }
}
