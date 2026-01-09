import QtQuick
import QtQuick.Layouts

Rectangle {
    id: sidebarRoot
    color: "#110e3d"
    
    signal pageSelected(int index)
    property int currentTab: 0

    ColumnLayout {
        anchors.fill: parent
        spacing: 5 // Reducimos un poco el espacio entre botones para que queden más compactos

        // Logo o Título de la App (Opcional, queda bien arriba del todo)
        Item { 
            Layout.preferredHeight: 80 
            Layout.fillWidth: true
            Text {
                text: "PINE"
                color: "white"
                font.bold: true
                font.pixelSize: 24
                anchors.centerIn: parent
            }
        }

        // --- BOTONES CON ICONOS ---
        
        SideBarButton { 
            text: "Clientes"
            iconSource: "qrc:/pine/qml/Assets/Icons/clientes.svg"
            isActive: sidebarRoot.currentTab === 0
            onClicked: {
                sidebarRoot.currentTab = 0
                sidebarRoot.pageSelected(0)
            }
        }
        
        SideBarButton { 
            text: "Expedientes"
            iconSource: "qrc:/pine/qml/Assets/Icons/expedientes.svg"
            isActive: sidebarRoot.currentTab === 1
            onClicked: {
                sidebarRoot.currentTab = 1
                sidebarRoot.pageSelected(1)
            }
        }

        SideBarButton { 
            text: "Fases"
            // Icono sugerido: un martillo o una lista de pasos
            iconSource: "qrc:/pine/qml/Assets/Icons/fases.svg" 
            isActive: sidebarRoot.currentTab === 2
            onClicked: {
                sidebarRoot.currentTab = 2
                sidebarRoot.pageSelected(2)
            }
        }

        SideBarButton { 
            text: "Actuaciones"
            // Icono sugerido: documento firmado o pluma
            iconSource: "qrc:/pine/qml/Assets/Icons/actuaciones.svg" 
            isActive: sidebarRoot.currentTab === 3
            onClicked: {
                sidebarRoot.currentTab = 3
                sidebarRoot.pageSelected(3)
            }
        }

        Item { Layout.fillHeight: true }

        SideBarButton { 
            text: "Salir"
            iconSource: "qrc:/pine/qml/Assets/Icons/salir.svg"
            onClicked: Qt.quit()
        }
        
        Item { Layout.preferredHeight: 20 } // Margen inferior
    }
}
