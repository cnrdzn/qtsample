import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

ColumnLayout {
    height: 300
    width: 400

    RadioButton {
        checked: true
        text: qsTr("First")
    }
    RadioButton {
        text: qsTr("Second")
    }
    RadioButton {
        text: qsTr("Third")
    }

    Text {
        id: text1
        text: qsTr("Text")
        font.pixelSize: 12
    }
}
