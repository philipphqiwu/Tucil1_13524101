import QtCore
import QtQuick
import QtQuick.Dialogs

ResultsScreenForm {
    required property var appFlow
    state: "landscape"

    FileDialog {
        id: saveFileDialog
        title: "Save board as PNG"
        fileMode: FileDialog.SaveFile
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        nameFilters: ["PNG files (*.png)"]
        onAccepted: {
            var path = selectedFile.toString().replace("file:///", "")
            if (!path.toLowerCase().endsWith(".png"))
                path += ".png"

            boardGrid.grabToImage(function(result) {
                if (result.saveToFile(path)) {
                    saveMsg.color = "#1FC974"
                    saveMsg.text = "Saved!"
                } else {
                    saveMsg.color = "#E6194B"
                    saveMsg.text = "Failed to save image"
                }
            })
        }
    }

    FileDialog {
        id: saveTxtDialog
        title: "Save board as TXT"
        fileMode: FileDialog.SaveFile
        currentFolder: StandardPaths.standardLocations(StandardPaths.DownloadLocation)[0]
        nameFilters: ["Text files (*.txt)"]
        onAccepted: {
            var path = selectedFile.toString()
            if (!path.toLowerCase().endsWith(".txt"))
                path += ".txt"

            if (QueensController.saveBoardAsTxt(path)) {
                saveMsg.color = "#1FC974"
                saveMsg.text = "Saved!"
            } else {
                saveMsg.color = "#E6194B"
                saveMsg.text = "Failed to save text file"
            }
        }
    }

    saveButton.onClicked: saveFileDialog.open()
    saveTxtButton.onClicked: saveTxtDialog.open()
    backToStartButton.onClicked: appFlow.backToStartButton()
}
