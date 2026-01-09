#include "Cliente.h"
#include <QJsonObject>

Cliente Cliente::fromJson(QJsonObject &json_cliente)
{
    Cliente cliente;

    if(json_cliente.contains("id"))
        cliente.id = json_cliente["id"].toInt();

    if(json_cliente.contains("nombre"))
        cliente.nombre = json_cliente["nombre"].toString();
    
    if(json_cliente.contains("cif"))
        cliente.cif = json_cliente["cif"].toString();

    if(json_cliente.contains("direccion"))
        cliente.direccion = json_cliente["direccion"].toString();

    if(json_cliente.contains("cod_postal"))
        cliente.cod_postal = json_cliente["cod_postal"].toInt();

    if(json_cliente.contains("pais"))
        cliente.pais = json_cliente["pais"].toString();

    if(json_cliente.contains("cuidad"))
        cliente.ciudad = json_cliente["ciudad"].toString();

    if(json_cliente.contains("comunidad"))
        cliente.ciudad = json_cliente["comunidad"].toString();

    return (cliente);
}

QJsonObject Cliente::toJson() const
{
    QJsonObject json_cliente;

    json_cliente["id"] = id;
    json_cliente["nombre"] = nombre;
    json_cliente["cif"] = cif;
    json_cliente["direccion"] = direccion;
    json_cliente["cod_postal"] = cod_postal;
    json_cliente["pais"] = pais;
    json_cliente["ciudad"] = ciudad;
    json_cliente["comunidad"] = comunidad;
    
    return (json_cliente);
}
