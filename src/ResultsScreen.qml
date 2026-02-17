// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

ResultsScreenForm {
    required property var appFlow
    state: "landscape"

    backToStartButton.onClicked: appFlow.backToStartButton()
}
