import QtQuick

CustomToolBarForm {
    id: root
    signal backClicked()
    signal themeChangeRequested()

    backButton.onClicked: root.backClicked()
    themeButton.onClicked: root.themeChangeRequested()

    backButton.states: State {
        name: "pressed"
        when: root.backButton.pressed
        PropertyChanges {
            target: backButton
            scale: 1.1
        }
    }
    themeButton.states: State {
        name: "pressed"
        when: root.themeButton.pressed
        PropertyChanges {
            target: themeButton
            scale: 1.1
        }
    }

}
