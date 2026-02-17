// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause
import QtQuick
SolvingScreenForm {
    required property var appFlow
    state: "landscape"

    Timer {
        id: timer
        interval: 3000
        running: true
        onTriggered: {
            appFlow.onGoToResults()
        }
    }
}
