import QtQuick

HomeForm {
    state: "landscape"

    grid.states: [
        State {
            name: "small"
            when: ((Screen.height * Screen.devicePixelRatio)
                   + (Screen.width * Screen.devicePixelRatio)) < 2000
            PropertyChanges {
                target: header
                font.pixelSize: 28
            }
            PropertyChanges {
                target: caption
                font.pixelSize: 14
            }
        }
    ]
}
