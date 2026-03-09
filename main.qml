import QtQuick 2.9
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.5
import com.launcher 1.0

import "qrc:/qml"

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("MiniGames Launcher")
    SelectUserMenu {
        id: selected_user_menu
    }
    StackLayout {
        id: stack
        anchors.fill: parent

        Column {
            anchors.fill: parent

            ListView {
                anchors.fill: parent
                model: 10
                delegate: Button {
                        text: "Game " + index
                }
            }

            Row {
                anchors.bottom: parent.bottom
                Button {
                    text: qsTr("Locale")
                }
                Button {
                    text: qsTr("Users")
                    onClicked: selected_user_menu.open()
                }
            }
        }

    }
    Component.onCompleted: {
        if (!Launcher.isUserSelected()){
            selected_user_menu.open()
        }
    }
}


