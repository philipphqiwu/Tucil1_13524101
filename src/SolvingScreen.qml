import QtQuick

SolvingScreenForm {
    required property var appFlow
    state: "landscape"

    Component.onCompleted: {
        QueensController.startSolving()
    }

    Timer {
        id: delayTimer
        interval: 1500
        repeat: false
        onTriggered: appFlow.onGoToResults()
    }

    Connections {
        target: QueensController
        function onSolveFinished(success) {
            delayTimer.start()
        }
    }
}
