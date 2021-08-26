import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    height: stackView.height
    width: stackView.width

    title: qsTr("Home")

    Label {
        text: qsTr("Hello world")
        anchors.centerIn: parent
    }
}
