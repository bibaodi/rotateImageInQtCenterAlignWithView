import QtQuick
import com.mycompany.Eton 1.0
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Rotate Image")

    EtonImage{
        id: id_image
        x:10
        y:10
        width:300
        height:300
    }

    EtonImage{
        id: id_image2
        x:320
        y:10
        width:300
        height:300
        Component.onCompleted: {
        this.setScale(0.9);
        }
    }
    Text {
        id: id_infox
        y: parent.height-50
        x: 30
        text: qsTr("click to scale, wheel to rotate")
    }
}
