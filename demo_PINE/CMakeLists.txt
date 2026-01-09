cmake_minimum_required(VERSION 3.16)

project(PINE VERSION 0.1 LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 COMPONENTS Quick REQUIRED)

qt_standard_project_setup()

# --- CAMBIO IMPORTANTE AQUÍ ---
# 1. Primero creamos el ejecutable con el punto de entrada (main.cpp)
qt_add_executable(Pine 
    src/main.cpp
)

# 2. Ahora definimos el módulo QML y lo "pegamos" al ejecutable 'Pine'
qt_add_qml_module(Pine
    URI "pine"
    VERSION 1.0
    RESOURCE_PREFIX "/" 
    
    # Archivos C++ (El resto de tu lógica)
    SOURCES
        # Nota: He quitado src/main.cpp de aquí porque ya está arriba
        
        # Models
        src/Models/Actuacion/Actuacion.h
        src/Models/Cliente/Cliente.h
        src/Models/Expediente/Expediente.h
        src/Models/Fase/Fase.h
        src/Models/Actuacion/Actuacion.cpp
        src/Models/Cliente/Cliente.cpp
        src/Models/Expediente/Expediente.cpp
        src/Models/Fase/Fase.cpp

        # Repository
        src/Repository/Repository.h       

        # Services
        src/Services/ActuacionService/ActuacionService.h
        src/Services/ActuacionService/ActuacionService.cpp
        src/Services/ClienteService/ClienteService.h
        src/Services/ClienteService/ClienteService.cpp
        src/Services/ExpedienteService/ExpedienteService.h
        src/Services/ExpedienteService/ExpedienteService.cpp
        src/Services/FaseService/FaseService.h
        src/Services/FaseService/FaseService.cpp

    # Archivos QML
    QML_FILES
        qml/main.qml
        qml/Componentes/SideBar.qml
        qml/Componentes/SideBarButton.qml
        qml/Pantallas/PaginaClientes.qml
        qml/Pantallas/PaginaExpedientes.qml

    RESOURCES
        qml/Assets/Icons/clientes.svg
        qml/Assets/Icons/expedientes.svg
        qml/Assets/Icons/fases.svg
        qml/Assets/Icons/actuaciones.svg
        qml/Assets/Icons/salir.svg
)

# 3. Configuración de Includes
target_include_directories(Pine PRIVATE
    src/Models
    src/Repositories/ActuacionRepository
    src/Repositories/ClienteRepository
    src/Repositories/ExpedienteRepository
    src/Repositories/FaseRepository
    src/Services/ActuacionService
    src/Services/ClienteService
    src/Services/ExpedienteService
    src/Services/FaseService
)

# Enlazar librerías de Qt
target_link_libraries(Pine PRIVATE Qt6::Quick)

# Evita consola en Windows (no afecta a Linux pero es buena práctica mantenerlo)
set_target_properties(Pine PROPERTIES WIN32_EXECUTABLE ON)
