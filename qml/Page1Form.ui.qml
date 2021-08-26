import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    height: stackView.height
    width: stackView.width
    title: qsTr("Page 1")

    Label {
        text: qsTr("You are on Page 1.")
        anchors.centerIn: parent
    }
}
