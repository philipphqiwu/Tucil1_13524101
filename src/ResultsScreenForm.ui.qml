// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
import QtQuick.Layouts

Item {
    id: resultsscreen
    property alias backToStartButton: backToStartButton
    property alias grid: grid
    // property alias caption: caption

    states: [
        State {
            name: "landscape"
            PropertyChanges {
                target: grid
                anchors.topMargin: 0
            }
            PropertyChanges {
                target: backToStartButton
                Layout.preferredWidth: resultsscreen.width / 4
                Layout.preferredHeight: resultsscreen.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: backToStartButton
                Layout.minimumHeight: 0
            }
        }
    ]

    GridLayout {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: resultsscreen.top
        flow: GridLayout.TopToBottom

        Text {
            id: header
            text: qsTr("Results")
            font.pixelSize: 32
            font.weight: 700
            color: Colors.currentTheme.textColor
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.topMargin: 20
        }

        CustomButton {
            id: backToStartButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.minimumWidth: 150
            Layout.minimumHeight: 40
            buttonText: "Back to start!"
        }


    }
}
