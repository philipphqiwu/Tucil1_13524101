import QtCore
import QtQuick
import QtQuick.Controls
import QtQuick.Dialogs

InputScreenForm {
    required property var appFlow
    state: "landscape"

    FileDialog {
        id: fileDialogTxt
        currentFolder: StandardPaths.standardLocations(StandardPaths.DownloadLocation)[0]
        nameFilters: ["Text files (*.txt)"]
        onAccepted: {
            QueensController.loadFromTxtFile(selectedFile)
        }
    }

    inputTxtButton.onClicked: fileDialogTxt.open()

    optimizeCheck.onCheckedChanged: {
        QueensController.useBacktracking = optimizeCheck.checked
    }

    goSolvingButton.onClicked: appFlow.onGoToSolving()
}
