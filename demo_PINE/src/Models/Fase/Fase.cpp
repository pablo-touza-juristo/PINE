#include "Fase.h"
#include <QJsonObject>
#include <QDate>

Fase Fase::fromJson(QJsonObject& json_fase)
{
    Fase fase;

    if(json_fase.contains("id"))
        fase.id = json_fase["id"].toInt();
    if(json_fase.contains("id_expediente"))
        fase.id_expediente = json_fase["id_expediente"].toInt();
    if(json_fase.contains("fecha_creacion"))
        fase.fecha_creacion = QDate::fromString(json_fase["fecha_creacion"].toString(), "dd/MM/yyyy");
    if(json_fase.contains("fecha_finalizacion"))
        fase.fecha_finalizacion = QDate::fromString(json_fase["fecha_finalizacion"].toString(), "dd/MM/yyyy");
    if(json_fase.contains("org_judicial"))
        fase.org_judicial = json_fase["org_judicial"].toString();
    if(json_fase.contains("procedimiento"))
        fase.procedimiento = json_fase["procedimiento"].toString();
    if(json_fase.contains("autos"))
        fase.autos = json_fase["autos"].toString();
    if(json_fase.contains("posicion"))
        fase.posicion = json_fase["posicion"].toString();
    if(json_fase.contains("nig"))
        fase.nig = json_fase["nig"].toString();
    if(json_fase.contains("cuantia"))
        fase.cuantia = json_fase["cuantia"].toString();
    if(json_fase.contains("intereses"))
        fase.intereses = json_fase["intereses"].toDouble();
    if(json_fase.contains("costas"))
        fase.costas = json_fase["costas"].toDouble();
    if(json_fase.contains("reconvencion"))
        fase.reconvencion = json_fase["reconvencion"].toString();
    if(json_fase.contains("importe_reconv"))
        fase.importe_reconv = json_fase["importe_reconv"].toDouble();



    return (fase);
}

QJsonObject Fase::toJson() const 
{
    QJsonObject json_fase;
    
    json_fase["id"] = id;
    json_fase["id_expediente"] = id_expediente;
    json_fase["fecha_creacion"] = fecha_creacion.toString("dd/MM/yyyy");
    json_fase["fecha_finalizacion"] = fecha_finalizacion.toString("dd/MM/yyyy");
    json_fase["org_judicial"] = org_judicial;
    json_fase["procedimiento"] = procedimiento;
    json_fase["autos"] = autos;
    json_fase["posicion"] = posicion;
    json_fase["nig"] = nig;
    json_fase["cuantia"] = cuantia;
    json_fase["intereses"] = intereses;
    json_fase["costas"] = costas;
    json_fase["reconvencion"] = reconvencion;
    json_fase["importe_reconv"] = importe_reconv;

    return (json_fase);
}
