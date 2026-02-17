import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Item {
    id: solvingscreen
    property alias grid: grid

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
        anchors.top: solvingscreen.top
        flow: GridLayout.TopToBottom

        Text {
            id: header
            text: QueensController.solving ? qsTr("Solving...") : qsTr("Done!")
            font.pixelSize: 32
            font.weight: 700
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
        }

        Text {
            id: iterText
            text: "Iteration: " + QueensController.iteration
            font.pixelSize: 16
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 5
        }

        BoardGrid {
            cellSize: Math.max(12, Math.min(40, Math.min(
                (solvingscreen.width * 0.85) / Math.max(1, QueensController.queensModel.boardSize),
                (solvingscreen.height * 0.55) / Math.max(1, QueensController.queensModel.boardSize)
            )))
            showQueens: true
            animateChanges: false
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 10
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            Layout.topMargin: 15
            spacing: 8

            Text {
                text: "Update every:"
                font.pixelSize: 14
                color: Colors.currentTheme.textColor
                anchors.verticalCenter: parent.verticalCenter
            }
            Slider {
                id: intervalSlider
                from: 1; to: 500; value: QueensController.updateInterval
                stepSize: 1
                width: 150
                onValueChanged: QueensController.updateInterval = value
            }
            Text {
                text: intervalSlider.value.toFixed(0) + " iter"
                font.pixelSize: 14
                color: Colors.currentTheme.textColor
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Row {
            Layout.alignment: Qt.AlignHCenter
            spacing: 8

            Text {
                text: "Delay:"
                font.pixelSize: 14
                color: Colors.currentTheme.textColor
                anchors.verticalCenter: parent.verticalCenter
            }
            Slider {
                id: delaySlider
                from: 0; to: 500; value: QueensController.delayMs
                stepSize: 5
                width: 150
                onValueChanged: QueensController.delayMs = value
            }
            Text {
                text: delaySlider.value.toFixed(0) + " ms"
                font.pixelSize: 14
                color: Colors.currentTheme.textColor
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
