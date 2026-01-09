import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Item {
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 40
        spacing: 30

        // --- CABECERA Y FILTROS ---
        // Usamos un RowLayout superior para separar filtros (izq) y botón (der)
        RowLayout {
            Layout.fillWidth: true
            spacing: 20

            // 1. Contenedor de Filtros (Borde negro redondeado)
            Rectangle {
                Layout.fillWidth: true
                Layout.preferredHeight: 140
                border.color: "black"
                border.width: 1
                radius: 12
                color: "transparent"

                ColumnLayout {
                    anchors.fill: parent
                    anchors.margins: 20
                    spacing: 15

                    // Fila 1: Cliente
                    Rectangle {
                        Layout.fillWidth: true; Layout.preferredHeight: 45
                        border.color: "black"; border.width: 1; radius: 25 // Radius alto para estilo "pill"
                        TextField {
                            anchors.fill: parent; leftPadding: 45; background: null
                            placeholderText: "Buscar por cliente"
                            verticalAlignment: Text.AlignVCenter
                            Text { text: "🔍"; anchors.left: parent.left; anchors.verticalCenter: parent.verticalCenter; leftPadding: 15 }
                        }
                    }

                    // Fila 2: Auto y Número
                    RowLayout {
                        spacing: 20
                        Rectangle {
                            Layout.fillWidth: true; Layout.preferredHeight: 45
                            border.color: "black"; border.width: 1; radius: 25
                            TextField {
                                anchors.fill: parent; leftPadding: 45; background: null
                                placeholderText: "Buscar por auto"
                                verticalAlignment: Text.AlignVCenter
                                Text { text: "🔍"; anchors.left: parent.left; anchors.verticalCenter: parent.verticalCenter; leftPadding: 15 }
                            }
                        }
                        Rectangle {
                            Layout.fillWidth: true; Layout.preferredHeight: 45
                            border.color: "black"; border.width: 1; radius: 25
                            TextField {
                                anchors.fill: parent; leftPadding: 45; background: null
                                placeholderText: "Buscar por Número"
                                verticalAlignment: Text.AlignVCenter
                                Text { text: "🔍"; anchors.left: parent.left; anchors.verticalCenter: parent.verticalCenter; leftPadding: 15 }
                            }
                        }
                    }
                }
            }

            // 2. Botón Nuevo Expediente
            Button {
                text: "+ Nuevo Expediente"
                Layout.preferredWidth: 200
                Layout.preferredHeight: 60
                // IMPORTANTE: Alineación superior para que cuadre con la caja de filtros
                Layout.alignment: Qt.AlignTop | Qt.AlignRight 
                
                contentItem: Text { 
                    text: parent.text; 
                    color: "white"; font.bold: true; font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter; verticalAlignment: Text.AlignVCenter 
                }
                background: Rectangle { color: "#221f60"; radius: 8 }
            }
        }

        // --- LISTA EXPEDIENTES ---
        ListView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            spacing: 15
            model: expedientesModel

            delegate: Rectangle {
                width: ListView.view.width
                height: 110
                radius: 12
                border.color: "black"
                border.width: 1.5
                color: "white"

                RowLayout {
                    anchors.fill: parent
                    anchors.margins: 25

                    // Info Principal
                    ColumnLayout {
                        Layout.fillWidth: true
                        spacing: 5
                        
                        RowLayout {
                            Text { text: model.titulo; font.pixelSize: 22; font.bold: true }
                            Text { text: "(" + model.materia + ")"; font.pixelSize: 16; color: "#555" }
                        }
                        
                        Text { 
                            text: model.descripcion
                            font.pixelSize: 14; color: "#333"
                            elide: Text.ElideRight; Layout.fillWidth: true
                        }
                    }

                    // Fechas y Autos
                    ColumnLayout {
                        Layout.alignment: Qt.AlignRight | Qt.AlignTop
                        spacing: 8
                        
                        Text { text: "Fecha de alta: " + model.fecha; font.pixelSize: 14; color: "#333" }
                        Text { text: "Autos: " + model.autos; font.pixelSize: 14; color: "#333" }
                    }
                }
            }
        }
    }

    // Datos Mock
    ListModel {
        id: expedientesModel
        ListElement { titulo: "Expediente 2025/001"; materia: "Penal"; descripcion: "Defensa preliminar caso García..."; fecha: "12/01/2025"; autos: "22/45" }
        ListElement { titulo: "Expediente 2025/002"; materia: "Civil"; descripcion: "Reclamación impago alquiler..."; fecha: "15/01/2025"; autos: "10/99" }
        ListElement { titulo: "Expediente 2025/003"; materia: "Admin"; descripcion: "Recurso multa tráfico..."; fecha: "20/01/2025"; autos: "05/12" }
    }
}
