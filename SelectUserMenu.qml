import QtQuick 2.0
import QtQuick.Controls 2.5

import com.launcher 1.0

Popup {
    id: popup
    closePolicy: Popup.CloseOnEscape
    anchors.centerIn: parent
    height: 400
    width: 200
    Popup {
        id: new_user_window
        width: 300
        height: 200
        Column{
            TextInput {
                width: 200
                height: 25
                font.pixelSize: 16

                id: input
            }
            Row{
                Button{
                    text: qsTr("Create")
                    onClicked: {
                        if (input.text!="" && !Launcher.hasUser(input.text)){
                            Launcher.addNewUser(input.text);
                            Launcher.setCurrentUser(input.text)
                        }
                        new_user_window.close();
                        users_list.updateUsersList()
                        input.text=""
                    }
                }
                Button {
                    text: qsTr("Cancel")
                    onClicked: new_user_window.close()
                }
            }
    }


        closePolicy: Popup.CloseOnEscape
    }

    Column {
        height: parent.height

        ListView {
            id: users_list
            anchors.fill: parent
            spacing: 10

            header: Text {
                text: qsTr("Users")
                font.pixelSize: 32
            }

            //property int selectedUser : 0
            ButtonGroup {
                id: userGroup
            }

            delegate:
                Row {
                    RadioButton {
                        id: index
                        text: modelData
                        font.pixelSize: 16
                        ButtonGroup.group: userGroup
                        checked: modelData === Launcher.getCurrentUser()
                        onClicked: {
                            Launcher.setCurrentUser(index.text)
                            selectButton.updateEnabled()
                        }
                    }
                    Button {
                        text: "X"
                        onClicked: {
                            Launcher.deleteUser(index.text)
                            users_list.updateUsersList()
                        }
                    }
                }


            function updateUsersList() {
                users_list.model = Launcher.getAllUsers()
                selectButton.updateEnabled()
            }
        }

        Row{
            anchors.bottom: parent.bottom
            Button{
                text: qsTr("New user")
                onClicked: new_user_window.open()
            }
            Button{
                id: selectButton
                text: qsTr("Select")
                onClicked: {
                    popup.close();
                }
                function updateEnabled(){
                    enabled = Launcher.isUserSelected()
                }
            }
        }
    }
    onOpened: {
        users_list.updateUsersList()
    }
}
