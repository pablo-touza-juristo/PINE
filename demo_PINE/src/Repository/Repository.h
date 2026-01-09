#ifndef REPOSITORY_H
#define REPOSITORY_H 

#include <QList>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDir>
#include <QFileInfo>
#include <algorithm>
#include <QDebug>

class QJsonObject;

template <typename T>
class Repository
{
    private:
        // PROPIEDADES
        QString ruta_json;
        QList<T> recursos;
        QString clave_json;

        // METODOS
        void inicializar_json();
        void cargar_json();
        void guardar_json();
        int nuevo_id();

    public:
        // CONSTRUCTOR
        Repository (QString _ruta_json, QString _clave_json) :
            ruta_json(_ruta_json), clave_json(_clave_json)
        {
            inicializar_json();

        }
        // METODOS
        QList<T> get_all();
        T* get_byId(int id_recurso);
        void add_recurso(T& _recurso);
        int delete_recurso(int id_recurso);
        int post_recurso(T& _recurso);
};

template <typename T>
void Repository<T>::inicializar_json()
{   
    // Obtenemos la información del archivo y extraemos la ruta de directorios
    QFileInfo info_archivo(ruta_json);
    QDir directorio_json = info_archivo.absoluteDir();

    // Comprobamos si existe el directorio
    if(!directorio_json.exists())
    {
        // Creamos la ruta completa del archivo, sin crear el archivo
        if(directorio_json.mkpath((".")))
        {
            // TODO Implementar Logger 
        }

        else
        {
            return;
        }
    }

    // Inicializamos el archivo
    QFile json(ruta_json);
    
    // Comprobamos si existe, si no existe lo creamos y ponemos un objeto vacio
    if(!json.exists())
    {
        if(json.open(QIODevice::WriteOnly))
        {
            json.write("{}");
            json.close();
        }
    }
}

template <typename T>
void Repository<T>::cargar_json()
{
    // Creamos un objeto con el archivo
    QFile json(ruta_json);

    // Abrimos el archivo en modo lectura y comprobamos si se ha abierto
    if(!json.open(QIODevice::ReadOnly))
    {
        // TODO Implementar códigos de retorno
        return;
    }
    recursos.clear();
    QByteArray datos = json.readAll();
    json.close();

    // Creamos un objeto JSON para registrar el error
    QJsonParseError error;
    // Obtenemos un JsonDocument que contiene todos los objetos
    QJsonDocument doc_json = QJsonDocument::fromJson(datos, &error);
    
    // Si el documento es nulo imprimimos el error por consola (Implementaré un logger cuando pueda)
    if(doc_json.isNull())
        qDebug() << "Error:" << error.errorString();
    
    // Si el archivo no está encapsulado en {} retornamos
    if(!doc_json.isObject())
        return;
    
    // Obtenemos el objeto raiz del documento
    QJsonObject raiz = doc_json.object();

    if(!raiz.contains(clave_json) || !raiz[clave_json].isArray())
        return;
    
    // Convertimos el array del objeto raiz a un objeto JsonArray
    QJsonArray array_recursos = raiz[clave_json].toArray();

    for(const QJsonValue &valor_json : array_recursos)
    {
        // Trasnformamos el JsonValue a un objeto genérico para parsearlo
        QJsonObject obj_recurso = valor_json.toObject();

        // Convertimos el JSON a T usando la función del struct
        T recurso = T::fromJson(obj_recurso);
        recursos.append(recurso);
    }

    return;
}

template <typename T>
void Repository<T>::guardar_json()
{
    // Creamos un array en donde cargar nuestros objetos
    QJsonArray array_recursos;

    // Guardamos todos los recurso como JsonObject en el array
    for(const T& recurso : recursos)
    {
        QJsonObject json_recurso = recurso.toJson();
        array_recursos.append(json_recurso);
    }

    // Creamos un JsonObject que será el objeto que contiene todos los datos
    QJsonObject raiz;
    // Creamos una propiedad en la raiz llamado clave_json que será un array 
    raiz[clave_json] = array_recursos;

    // Creamos un JsonDocument para tener poder pasar nuestro objeto raiz a texto
    // en formato JSON
    QJsonDocument doc_json;
    
    // Añadimos nuestra raiz al documento 
    doc_json.setObject(raiz);
    
    // Una vez que tenemos el documento listo abrimos el archivo en modo escritura
    QFile archivo_json(ruta_json);
    if(!archivo_json.open(QIODevice::WriteOnly))
        return;

    // Obtenemos el documento como texto pero en formato JSON y lo escribimos en el fichero
    archivo_json.write(doc_json.toJson());
    archivo_json.close();

    return;
}

template <typename T>
int Repository<T>::nuevo_id()
{
    auto iterador = std::max(recursos.begin(), recursos.end(), 
            [](const T& _recurso_a, T& _recurso_b) {return (_recurso_a.id < _recurso_b.id);});

    return (iterador->id + 1);
}

// METODOS DEL CRUD
template <typename T>
QList<T> Repository<T>::get_all()
{
    return (recursos);
}

template <typename T>
T* Repository<T>::get_byId(int id_recurso)
{
    // Usamos find_if para buscar de una forma óptima usando un lambda
    // find_if retorna un iterador que contiene una referencia a nuestro objeto
    auto iterador = std::find_if(recursos.begin(), recursos.end(),
            [id_recurso](const T& recurso)
            {
                return recurso.id == id_recurso;
            });
    
    // Comprobamos si se ha encontrado el recurso
    if(iterador == recursos.end())
        return (nullptr);

    // Retornamos un puntero al recurso al que hace referencia el iterador
    return &(*iterador);
}

template <typename T>
void Repository<T>::add_recurso(T& _recurso)
{
    recursos.append(_recurso);    
}

template <typename T>
int Repository<T>::delete_recurso(int id_recurso)
{
    // Buscamos el recurso usando find_if para obtener un iterador con el recurso
    auto iterador = std::find_if(recursos.begin(), recursos.end(),
            [id_recurso](const T& recurso) { return recurso.id == id_recurso; });
    
    // Comprobamos si se ha encontrado
    if(iterador == recursos.end())
        return (0);
    
    // Borramos el recurso 
    recursos.erase(iterador);
    return (1);
}

template <typename T>
int Repository<T>::post_recurso(T& _recurso)
{
    // Buscamos el recurso usando el id
    auto iterador = std::find_if(recursos.begin(), recursos.end(),
        [_recurso](const T& recurso) {return recurso.id == _recurso.id;});
    
    // Comprobamos si lo hemos encontrado
    if(iterador == recursos.end())
        return (0);
    
    // Reemplazamos el recurso entero con los datos nuevos
    *iterador = _recurso;
    return (1);
}

#endif
