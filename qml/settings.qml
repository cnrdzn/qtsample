import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.LocalStorage
import Qt.labs.settings
Page {
    height: stackView.height
    width: stackView.width
    title: qsTr("Settings")
    leftPadding: 15
    rightPadding: 15
    topPadding: 15

    Column {

        Text {
            id: text1
            text: qsTr("Please select your Language")
            font.pixelSize: 18
        }
        ColumnLayout {
            id: langlist
            RadioButton {
                checked: true
                state: "en"
                text: qsTr("English")
            }
            RadioButton {
                state: "tr"
                text: qsTr("Türkçe")
            }
            RadioButton {
                state: "ru"
                text: qsTr("Pусский")
            }
        }
        ButtonGroup {
            buttons: langlist.children
            onClicked: {

                //console.log(button.id);
                ayars.selectLanguage(button.state);
                /*
                var stringArray = langlist.children;

                for (var i = 0; i < stringArray.length ; i++)
                {
                    stringArray[i];
                    console.log(stringArray[i].text);
                }*/
            }
        }
    }
}
