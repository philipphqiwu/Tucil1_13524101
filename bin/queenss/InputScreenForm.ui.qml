import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: inputscreen
    property alias inputTxtButton: inputTxtButton
    property alias goSolvingButton: goSolvingButton
    property alias optimizeCheck: optimizeCheck
    property alias grid: grid

    states: [
        State {
            name: "landscape"
            PropertyChanges {
                target: grid
                anchors.topMargin: 0
            }
            PropertyChanges {
                target: inputTxtButton
                Layout.preferredWidth: inputscreen.width / 4
                Layout.preferredHeight: inputscreen.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: inputTxtButton
                Layout.minimumHeight: 0
            }
        }
    ]

    GridLayout {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.centerIn: parent
        flow: GridLayout.TopToBottom

        Text {
            id: header
            text: qsTr("Input")
            font.pixelSize: 32
            font.weight: 700
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
        }

        CustomButton {
            id: inputTxtButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.minimumWidth: 150
            Layout.minimumHeight: 40
            buttonText: "Input From Txt"
        }

        Text {
            id: errorText
            text: QueensController.errorMessage
            color: "#E6194B"
            visible: text.length > 0
            font.pixelSize: 14
            wrapMode: Text.Wrap
            Layout.alignment: Qt.AlignHCenter
            Layout.maximumWidth: inputscreen.width * 0.8
        }

        BoardGrid {
            visible: QueensController.boardLoaded
            cellSize: Math.min(28, (inputscreen.width * 0.6) / Math.max(1, QueensController.queensModel.boardSize))
            showQueens: false
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 10
        }

        Text {
            visible: QueensController.boardLoaded
            text: "Board: " + QueensController.queensModel.boardSize + "x" + QueensController.queensModel.boardSize
            color: Colors.currentTheme.textColor
            font.pixelSize: 14
            Layout.alignment: Qt.AlignHCenter
        }

        Row {
            visible: QueensController.boardLoaded
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 10
            spacing: 12

            CustomButton {
                id: goSolvingButton
                width: 150
                height: 40
                buttonText: "Solve!"
                buttonColor: "green"
            }

            Row {
                anchors.verticalCenter: parent.verticalCenter
                spacing: 4

                CheckBox {
                    id: optimizeCheck
                    checked: true
                }

                Text {
                    text: "Optimize"
                    color: Colors.currentTheme.textColor
                    font.pixelSize: 14
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
        }
    }
}
