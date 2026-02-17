// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
import QtQuick.Layouts

Item {
    id: inputscreen
    property alias inputTxtButton: inputTxtButton
    property alias inputImgButton: inputImgButton
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
                target: inputTxtButton
                Layout.preferredWidth: inputscreen.width / 4
                Layout.preferredHeight: inputscreen.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: inputTxtButton
                Layout.minimumHeight: 0
            }
            PropertyChanges {
                target: inputImgButton
                Layout.preferredWidth: inputscreen.width / 4
                Layout.preferredHeight: inputscreen.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: inputImgButton
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
            text: qsTr("Input Text / Image")
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

        CustomButton {
            id: inputImgButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.minimumWidth: 150
            Layout.minimumHeight: 40
            buttonText: "Input From Png"
        }


    }
}
