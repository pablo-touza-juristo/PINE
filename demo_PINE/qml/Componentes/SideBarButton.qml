import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

AbstractButton {
    id: control
    
    property string iconSource: ""
    property bool isActive: false

    Layout.fillWidth: true
    Layout.preferredHeight: 55 // Un poco más alto para que respire mejor

    // --- CONTENIDO (Icono + Texto) ---
    contentItem: RowLayout {
        spacing: 15
        // Añadimos un poco de margen izquierdo para que el texto no pegue al borde
        // ahora que tenemos la barra vertical
        anchors.left: parent.left
        anchors.leftMargin: 20 
        
        // Icono
        Item {
            Layout.preferredWidth: 24
            Layout.preferredHeight: 24
            Layout.alignment: Qt.AlignVCenter

            Image {
                anchors.fill: parent
                source: control.iconSource
                sourceSize.width: 24
                sourceSize.height: 24
                visible: control.iconSource !== ""
                fillMode: Image.PreserveAspectFit
                // Truco: Si tus iconos son negros, esto no los vuelve blancos automáticamente.
                // Asegúrate de que tus SVGs tengan fill="white" o usa ColorOverlay.
            }
        }

        // Texto
        Text {
            text: control.text
            color: "white"
            // Si está activo, lo ponemos un poco más brillante/negrita
            font.bold: control.isActive 
            font.pixelSize: 16
            font.family: "Arial"
            
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignVCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    // --- FONDO Y BORDE IZQUIERDO (El cambio principal) ---
    background: Rectangle {
        // Color de fondo: Blanco al 10% de opacidad si está activo, transparente si no.
        color: control.isActive ? Qt.rgba(1, 1, 1, 0.1) : "transparent"
        
        // Borde vertical izquierdo
        Rectangle {
            width: 4 // Grosor del borde
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            color: "white"
            visible: control.isActive // Solo visible si está activo
        }
    }
}
