import QtQuick

Item {
    id: root

    // Configurable properties
    property int cellSize: 40
    property bool showQueens: true
    property bool animateChanges: false

    // Auto-size based on board
    width: grid.width
    height: grid.height

    Grid {
        id: grid
        columns: QueensController.queensModel.boardSize
        rows: QueensController.queensModel.boardSize

        Repeater {
            model: QueensController.queensModel

            Rectangle {
                width: root.cellSize
                height: root.cellSize
                color: cellColor
                border.color: Colors.currentTheme === Colors.dark ? "#555" : "#999"
                border.width: 1
                radius: 2

                Text {
                    anchors.centerIn: parent
                    text: hasQueen && root.showQueens ? "♛" : ""
                    font.pixelSize: root.cellSize * 0.55
                    color: "white"
                    style: Text.Outline
                    styleColor: "#333"
                }

                Behavior on color {
                    enabled: root.animateChanges
                    ColorAnimation { duration: 120 }
                }
            }
        }
    }
}
