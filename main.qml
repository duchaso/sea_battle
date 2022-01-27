import QtQuick 2.15
import QtQuick.Window 2.15
import SeaBoard 1.0

Window {
    width: 800
    height: 800
    visible: true
    title: qsTr("Sea Battle")

    BoardModel {
        id: bModel
    }

    GridView {
        id: gd_view
        anchors.fill: parent

        cellHeight: height/10
        cellWidth: width/10
        delegate: delegateItem
        model: bModel
    }
    Component{
        id: delegateItem
        Item {
            width: gd_view.cellWidth; height: gd_view.cellHeight
            property bool cellType: CellType
            property int indexOfThisDelegate: index
            Rectangle {
                width: parent.width-5; height: parent.height-5
                color: (ExploseType) ? "red" : "green"
                anchors.centerIn: parent
                MouseArea {
                    anchors.fill: parent
                    onClicked: { bModel.explose(index) }
                }
            }
            Text {
                id: txt
                text: (CellType) ? "  . (|   .\n(|  (|  (|\n_|__|__|_\n \\_____/" : "/\/\/\/\/\/"
                anchors.centerIn: parent
            }
        }
      }

}
