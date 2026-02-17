// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

HowToPlayForm {
    required property var appFlow
    state: "landscape"

    goSolvingButton.onClicked: appFlow.goSolvingButton()
}
