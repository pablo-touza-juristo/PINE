#ifndef CLIENTE_H
#define CLIENTE_H

#include <QString>

class QJsonObject;

struct Cliente
{
    int id;
    QString nombre;
    QString cif;
    QString direccion;
    int cod_postal;
    QString pais;
    QString ciudad;
    QString comunidad;

    Cliente() {}

    Cliente(int _id, QString _nombre, QString _cif, QString _direccion, int _cod_postal, QString _pais, QString _ciudad, QString _comunidad) :
    id(_id), nombre(_nombre), cif(_cif), direccion(_direccion), cod_postal(_cod_postal), pais(_pais), ciudad(_ciudad), comunidad(_comunidad)
    {}
    
    static Cliente fromJson(QJsonObject& json_cliente);
    QJsonObject toJson() const;
};

#endif 
