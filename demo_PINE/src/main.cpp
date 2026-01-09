#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
    // 1. Inicializa la aplicación GUI
    QGuiApplication app(argc, argv);

    // Configura metadatos básicos (opcional pero recomendado)
    app.setOrganizationName("MiEmpresa");
    app.setOrganizationDomain("miempresa.com");
    app.setApplicationName("PINE");

    // 2. Inicializa el motor de QML
    QQmlApplicationEngine engine;

    // 3. Define la ruta del archivo principal
    // Como en el CMake pusimos RESOURCE_PREFIX "/", la ruta es tal cual la estructura de carpetas
    const QUrl url("qrc:/pine/qml/main.qml");

    // 4. Conecta una señal para saber si falló la carga (útil para debug)
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    // 5. Carga el QML
    engine.load(url);

    // 6. Arranca el bucle de eventos
    return app.exec();
}
