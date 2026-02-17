// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
import QtQuick.Layouts

Item {
    id: howtoplay
    property alias goSolvingButton: goSolvingButton
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
                target: goSolvingButton
                Layout.preferredWidth: howtoplay.width / 4
                Layout.preferredHeight: howtoplay.height / 8
                Layout.topMargin: 0
            }
            PropertyChanges {
                target: goSolvingButton
                Layout.minimumHeight: 0
            }
        }
    ]

    GridLayout {
        id: grid
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: howtoplay.top
        flow: GridLayout.TopToBottom
        GridLayout {
            id: innerGrid
            columns: 2
            rows: 2
            rowSpacing: 10
            columnSpacing: 10
            Image {
                id: rule1
                Layout.preferredHeight: howtoplay.height / 3
                Layout.preferredWidth: howtoplay.height / 3.2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.margins: 5
                source: "./Resources/images/boards/rule1.png"
            }
            Image {
                id: rule2
                Layout.preferredHeight: howtoplay.height / 3
                Layout.preferredWidth: howtoplay.height / 3.2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.margins: 5
                source: "./Resources/images/boards/rule2.png"
            }
            Image {
                id: rule3
                Layout.preferredHeight: howtoplay.height / 3
                Layout.preferredWidth: howtoplay.height / 3.2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.margins: 5
                source: "./Resources/images/boards/rule3.png"
            }
            Image {
                id: rule4
                Layout.preferredHeight: howtoplay.height / 3
                Layout.preferredWidth: howtoplay.height / 3.2
                Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
                Layout.margins: 5
                source: "./Resources/images/boards/rule4.png"
            }
        }

        CustomButton {
            id: goSolvingButton
            Layout.alignment: Qt.AlignHCenter | Qt.AlignTop
            Layout.minimumWidth: 150
            Layout.minimumHeight: 40
            buttonText: "Go Solving"
        }
    }
}
