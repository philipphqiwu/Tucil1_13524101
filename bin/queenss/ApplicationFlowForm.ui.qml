import QtQuick
import QtQuick.Controls.Basic

Rectangle {
    // Height, width and any other size related properties containing odd looking float or other dividers
    // that do not seem to have any logical origin are just arbitrary and based on original design
    // and/or personal preference on what looks nice.
    id: root
    color: Colors.currentTheme.background
    property string previousState: ""
    property alias toolbar: toolbar
    property alias pageText: pageText
    property alias howToPlay: howToPlay
    property alias inputScreen: inputScreen
    property alias solvingScreen: solvingScreen
    property alias resultsScreen: resultsScreen
    property alias stack: stack

    CustomToolBar {
        id: toolbar
        anchors.topMargin: parent.height / 80
        width: parent.width
        height: 35
        anchors.top: parent.top
    }
    Text {
        id: pageText
        text: "Queens Solver"
        font.pixelSize: 24
        font.family: "Titillium Web"
        font.weight: 700
        color: Colors.currentTheme.textColor
        anchors.top: toolbar.bottom
        anchors.topMargin: parent.height / 20
        leftPadding: 20
    }
    //! [Stack view]
    StackView {
        id: stack
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.topMargin: parent.height / 20

        pushEnter: Transition {
            PropertyAnimation {
                property: "x"
                from: stack.width
                to: 0
                duration: 400
            }
        }
        //! [Stack view]
        pushExit: Transition {
            PropertyAnimation {
                property: "x"
                from: 0
                to: -stack.width
                duration: 400
            }
        }
        popEnter: Transition {
            PropertyAnimation {
                property: "x"
                from: -stack.width
                to: 0
                duration: 400
            }
        }
        popExit: Transition {
            PropertyAnimation {
                property: "x"
                from: 0
                to: stack.width
                duration: 400
            }
        }
    }

    Component {
        id: howToPlay
        HowToPlay {
            visible: true
        }
    }

    Component {
        id: inputScreen
        InputScreen {}
    }

    Component {
        id: solvingScreen
        SolvingScreen {}
    }

    Component {
        id: resultsScreen
        ResultsScreen {}
    }

}
