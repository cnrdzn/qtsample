import QtQuick
import QtQuick.Controls
import QtQuick.XmlListModel 2.0

Page {
    height: stackView.height
    width: stackView.width

    title: qsTr("Page 2")

    Label {
        text: qsTr("You are on Page 2.")
        anchors.centerIn: parent
    }
    XmlListModel {
        id: xmlModel
        source: "http://www.mysite.com/feed.xml"
        query: "/rss/channel/item"

        XmlRole {
            name: "title"
            query: "title/string()"
        }
        XmlRole {
            name: "pubDate"
            query: "pubDate/string()"
        }
    }
}
