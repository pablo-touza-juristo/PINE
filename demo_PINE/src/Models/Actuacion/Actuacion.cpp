#include "Actuacion.h"
#include <QJsonObject>
#include <QDate>

Actuacion Actuacion::fromJson(QJsonObject &json_actuacion)
{
    Actuacion actuacion;
    
    if(json_actuacion.contains("id"))
        actuacion.id = json_actuacion["id"].toInt();
    if(json_actuacion.contains("id_fase"))
        actuacion.id_fase = json_actuacion["id_fase"].toInt();
    if(json_actuacion.contains("tipo"))
        actuacion.tipo = json_actuacion["tipo"].toString();
    if(json_actuacion.contains("fecha_creacion"))
        actuacion.fecha_creacion = QDate::fromString(json_actuacion["fecha_creacion"].toString(), "dd/MM/yyyy");
    if(json_actuacion.contains("fecha_cierre"))
        actuacion.fecha_cierre = QDate::fromString(json_actuacion["fecha_cierre"].toString(), "dd/MM/yyyy");
    if(json_actuacion.contains("duracion"))
        actuacion.duracion = json_actuacion["duracion"].toInt();
    if(json_actuacion.contains("importe"))
        actuacion.importe = json_actuacion["importe"].toDouble();
    if(json_actuacion.contains("codigo"))
        actuacion.codigo = json_actuacion["codigo"].toString();
    if(json_actuacion.contains("texto"))
        actuacion.texto = json_actuacion["texto"].toString();
 
    return (actuacion);
}

QJsonObject Actuacion::toJson() const
{
    QJsonObject json_actuacion;
    json_actuacion["id"] = id;
    json_actuacion["id_fase"] = id_fase;
    json_actuacion["tipo"] = tipo;
    json_actuacion["fecha_creacion"] = fecha_creacion.toString("dd/MM/yyyy");
    json_actuacion["fecha_cierre"] = fecha_cierre.toString("dd/MM/yyyy");
    json_actuacion["duracion"] = duracion;
    json_actuacion["importe"] = importe;
    json_actuacion["codigo"] = codigo;
    json_actuacion["texto"] = texto;
    
    return (json_actuacion);
}
