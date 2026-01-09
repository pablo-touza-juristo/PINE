import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

// Importar carpetas relativas para usar los componentes dentro
import "Componentes" 
import "Pantallas" 

ApplicationWindow {
    visible: true
    width: 1280
    height: 720
    title: "PINE - Gestión Jurídica"
    color: "#f4f4f4" // Fondo gris muy claro

    RowLayout {
        anchors.fill: parent
        spacing: 0

        // 1. Barra Lateral (SideBar)
        SideBar {
            Layout.preferredWidth: 250
            Layout.fillHeight: true
            
            onPageSelected: (index) => {
                stackLayout.currentIndex = index
            }
        }

        // 2. Área de Contenido
        Rectangle {
            Layout.fillWidth: true
            Layout.fillHeight: true
            color: "transparent"
            clip: true

            StackLayout {
                id: stackLayout
                anchors.fill: parent
                anchors.margins: 30
                currentIndex: 0 // 0 = Clientes, 1 = Expedientes

                // Índice 0: Pantalla Clientes
                PaginaClientes {}

                // Índice 1: Pantalla Expedientes
                PaginaExpedientes {}
                
                // Placeholder para otras páginas
                Item { Text { text: "Fases (En construcción)"; anchors.centerIn: parent } }
                Item { Text { text: "Actuaciones (En construcción)"; anchors.centerIn: parent } }
            }
        }
    }
}
