import QtQuick
import QtQuick.Layouts

Item {
    id: resultsscreen
    property alias backToStartButton: backToStartButton
    property alias saveButton: saveButton
    property alias saveTxtButton: saveTxtButton
    property alias saveMsg: saveMsg
    property alias grid: grid
    property alias boardGrid: boardGrid

    states: [
        State {
            name: "landscape"
            PropertyChanges {
                target: grid
                anchors.topMargin: 0
            }
        }
    ]

    GridLayout {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: resultsscreen.top
        flow: GridLayout.TopToBottom
        rowSpacing: 8

        Text {
            id: header
            text: QueensController.solved ? qsTr("Solution Found!") : qsTr("No Solution Found")
            font.pixelSize: 32
            font.weight: 700
            color: QueensController.solved ? "#1FC974" : "#E6194B"
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
        }

        BoardGrid {
            id: boardGrid
            cellSize: Math.min(44, (resultsscreen.width * 0.7) / Math.max(1, QueensController.queensModel.boardSize))
            showQueens: true
            animateChanges: false
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 6
        }

        Text {
            text: "Iterations: " + QueensController.iteration
            font.pixelSize: 16
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 6
        }

        Text {
            text: "Time: " + QueensController.elapsedMs.toFixed(1) + " ms"
            font.pixelSize: 16
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter
        }

        Text {
            id: saveMsg
            text: ""
            font.pixelSize: 14
            color: "#1FC974"
            Layout.alignment: Qt.AlignHCenter
            visible: text.length > 0
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            spacing: 20
            Layout.topMargin: 12

            CustomButton {
                id: saveButton
                width: 160
                height: 44
                buttonText: "Save as PNG"
                buttonColor: "green"
            }

            CustomButton {
                id: saveTxtButton
                width: 160
                height: 44
                buttonText: "Save as TXT"
                buttonColor: "green"
            }

            CustomButton {
                id: backToStartButton
                width: 160
                height: 44
                buttonText: "Back to start!"
            }
        }
    }
}
