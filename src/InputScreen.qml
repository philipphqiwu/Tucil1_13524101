// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
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
        onAccepted: appFlow.onGoToSolving()
    }

    FileDialog {
        id: fileDialogImg
        currentFolder: StandardPaths.standardLocations(StandardPaths.PicturesLocation)[0]
        nameFilters: ["Image files (*.png)"]
        // onAccepted: image.source = selectedFile
    }

    inputTxtButton.onClicked: fileDialogTxt.open()
    inputImgButton.onClicked: fileDialogImg.open()

}
