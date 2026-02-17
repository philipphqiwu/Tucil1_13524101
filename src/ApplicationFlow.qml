import QtQuick

ApplicationFlowForm {
    id: applicationFlow
    state: "Home"
    property int animationDuration: 400
    property string platform: Qt.platform.os

    stack.initialItem: Home {
        id: home
        visible: true
        //! [On clicked]
        getStartedbutton.onClicked: {
            applicationFlow.state = "How-to-play"
            applicationFlow.stack.pushItem(applicationFlow.howToPlay, {appFlow: applicationFlow})
        }
        //! [On clicked]
    }

    //! [Theme button]
    function themeButton() {
        if (Colors.currentTheme == Colors.dark) {
            Colors.currentTheme = Colors.light
        } else {
            Colors.currentTheme = Colors.dark
        }
    }

    function goSolvingButton() {
        applicationFlow.state = "Input"
        stack.pushItem(applicationFlow.inputScreen, {appFlow: applicationFlow})
    }

    function onGoToSolving() {
        applicationFlow.state = "Solving"
        stack.pushItem(applicationFlow.solvingScreen, {appFlow: applicationFlow})
    }

    function backButton() {
        stack.pop()
        applicationFlow.state = applicationFlow.previousState
    }

    function onGoToResults() {
        applicationFlow.state = "Results"
        stack.pushItem(applicationFlow.resultsScreen, {appFlow: applicationFlow})
    }

    function backToStartButton() {
        stack.pop(stack.get(0))
        applicationFlow.state = "Home"
    }

    toolbar.onBackClicked: applicationFlow.backButton()
    toolbar.onThemeChangeRequested: applicationFlow.themeButton()

    //! [States]
    states: [
        State {
            name: "Home"
            PropertyChanges {
                target: toolbar
                backButton.opacity: 0
                backButton.enabled: false
            }
            //! [States]
            PropertyChanges {
                target: pageText
                visible: false
            }
            PropertyChanges {
                target: stack
                anchors.top: pageText.bottom
            }


        },
        State {
            name: "How-to-play"
            PropertyChanges {
                target: applicationFlow
                previousState: "Home"

            }
            PropertyChanges {
                target: pageText
                text: "How To Play"
            }

            PropertyChanges {
                target: stack
                anchors.top: pageText.bottom
            }
        },
        State {
            name: "Input"
            PropertyChanges {
                target: applicationFlow
                previousState: "How-to-play"

            }
            PropertyChanges {
                target: pageText
                text: "Input"
            }

            PropertyChanges {
                target: stack
                anchors.top: pageText.bottom
            }
        },
        State {
            name: "Solving"
            PropertyChanges {
                target: applicationFlow
                previousState: "Input"

            }
            PropertyChanges {
                target: pageText
                text: "Solving"
            }

            PropertyChanges {
                target: stack
                anchors.top: pageText.bottom
            }
        },
        State {
            name: "Results"

            PropertyChanges {
                target: toolbar
                backButton.opacity: 0
                backButton.enabled: false
            }

            PropertyChanges {
                target: pageText
                text: "Results"
            }

            PropertyChanges {
                target: stack
                anchors.top: pageText.bottom
            }
        }
    ]
}
