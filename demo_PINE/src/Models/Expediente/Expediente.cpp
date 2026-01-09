#include "Expediente.h"
#include <QJsonObject>
#include <qdatetime.h>

Expediente Expediente::fromJson(QJsonObject& json_expediente)
{
    Expediente expediente;

    if(json_expediente.contains("id"))
        expediente.id = json_expediente["id"].toInt();
    if(json_expediente.contains("id_cliente"))
        expediente.id_cliente = json_expediente["id_cliente"].toInt();
    if(json_expediente.contains("estado"))
        expediente.estado = json_expediente["estado"].toString();
    if(json_expediente.contains("materia"))
        expediente.materia = json_expediente["materia"].toString();
    if(json_expediente.contains("descripcion"))
        expediente.descripcion = json_expediente["descripcion"].toString();
    if(json_expediente.contains("contrario"))
        expediente.contrario = json_expediente["contrario"].toString();
    if(json_expediente.contains("year"))
        expediente.year = json_expediente["year"].toInt();
    if(json_expediente.contains("numero"))
        expediente.numero = json_expediente["numero"].toInt();
    if(json_expediente.contains("autos"))
        expediente.autos = json_expediente["autos"].toString();
    if(json_expediente.contains("fecha_alta"))
        expediente.fecha_alta = QDate::fromString(json_expediente["fecha_alta"].toString(), "dd/MM/yyyy");
    if(json_expediente.contains("fecha_cierre"))
        expediente.fecha_cierre = QDate::fromString(json_expediente["fecha_alta"].toString(), "dd/MM/yyyy");

    return (expediente);
}

QJsonObject Expediente::toJson() const
{
    QJsonObject json_expediente;

    json_expediente["id"] = id;
    json_expediente["id_cliente"] = id_cliente;
    json_expediente["estado"] = estado;
    json_expediente["fecha_alta"] = fecha_alta.toString("dd/MM/yyyy");
    json_expediente["fecha_cierre"] = fecha_cierre.toString("dd/MM/yyyy");
    json_expediente["materia"] = materia;
    json_expediente["descripcion"] = descripcion;
    json_expediente["contrario"] = contrario;
    json_expediente["year"] = year;
    json_expediente["numero"] = numero;
    json_expediente["autos"] = autos;

    return (json_expediente);
}
