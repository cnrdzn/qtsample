import QtQuick 2.12
import QtQuick.Controls
import QtQuick.Layouts

Item {
    title: qsTr("Settings")
    height: 500
    transformOrigin: Item.Center
    width: 400

    Text {
        id: text1
        text: qsTr("Text")
        font.pixelSize: 12
    }

    Text {
        id: text2
        x: 0
        y: 14
        text: qsTr("Text")
        font.pixelSize: 12
    }

    Column {
        id: row
        x: 110
        y: 33
        width: 200
        height: 400

        Text {
            id: text3
            text: qsTr("Text")
            font.pixelSize: 12
        }

        Text {
            id: text4
            text: qsTr("Text")
            font.pixelSize: 12
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/

