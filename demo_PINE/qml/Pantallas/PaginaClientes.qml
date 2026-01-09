import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 40 // Margen generoso alrededor de la página
        spacing: 30

        // --- CABECERA (Buscador + Botón) ---
        RowLayout {
            Layout.fillWidth: true
            spacing: 20

            // Campo de búsqueda
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 50
                border.color: "black"
                border.width: 1
                radius: 8
                color: "white"

                TextField {
                    anchors.fill: parent
                    leftPadding: 45
                    placeholderText: "Buscar cliente"
                    background: null
                    font.pixelSize: 16
                    verticalAlignment: Text.AlignVCenter
                    
                    Text { 
                        text: "🔍"
                        anchors.left: parent.left
                        anchors.verticalCenter: parent.verticalCenter
                        leftPadding: 15
                        font.pixelSize: 18
                    }
                }
            }

            // Botón Nuevo Cliente
            Button {
                text: "+ Nuevo Cliente"
                Layout.preferredHeight: 50
                Layout.preferredWidth: 200
                // IMPORTANTE: Usamos Alignment, NO anchors.right
                Layout.alignment: Qt.AlignRight 
                
                contentItem: Text {
                    text: parent.text
                    color: "white"
                    font.bold: true
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                background: Rectangle {
                    color: "#221f60"
                    radius: 8
                }
            }
        }

        // --- GRID DE TARJETAS ---
        GridView {
            id: viewClientes // <--- ID NECESARIO PARA EL DELEGATE
            
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            
            // Configuración de celdas
            cellWidth: width / 3 // 3 columnas
            cellHeight: 240
            
            model: clientesModel

            delegate: Rectangle {
                // Referenciamos por ID para evitar "ReferenceError"
                width: viewClientes.cellWidth - 20 
                height: viewClientes.cellHeight - 20
                
                // Centramos visualmente en la celda
                x: 10
                y: 10

                radius: 12
                border.color: "black"
                border.width: 1.5
                color: "white"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 25
                    spacing: 15

                    Text {
                        text: model.nombre
                        font.pixelSize: 24
                        font.family: "Arial"
                        color: "black"
                        Layout.fillWidth: true
                        elide: Text.ElideRight
                    }

                    // Datos
                    ColumnLayout {
                        spacing: 8
                        Text { 
                            text: "Exp. Totales: " + model.totales
                            font.pixelSize: 16
                            color: "#333" 
                        }
                        Text { 
                            text: "Exp. Vivos: " + model.vivos
                            font.pixelSize: 16
                            color: "#333" 
                        }
                    }
                    
                    Item { Layout.fillHeight: true } // Spacer inferior
                }
            }
        }
    }

    // Datos de prueba
    ListModel {
        id: clientesModel
        ListElement { nombre: "Proforma S.L."; totales: 15; vivos: 4 }
        ListElement { nombre: "García & Asociados"; totales: 8; vivos: 2 }
        ListElement { nombre: "Transportes Pepe"; totales: 22; vivos: 10 }
        ListElement { nombre: "Inmobiliaria Centro"; totales: 5; vivos: 1 }
        ListElement { nombre: "Juan Pérez"; totales: 1; vivos: 0 }
        ListElement { nombre: "Tech Solutions"; totales: 12; vivos: 6 }
    }
}
