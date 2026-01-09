#ifndef FASE_H
#define FASE_H

#include <QString>
#include <QDate>

struct Fase
{
    int id;
    int id_expediente;
    QDate fecha_creacion;
    QDate fecha_finalizacion;
    QString org_judicial;
    QString procedimiento;
    QString autos;
    QString posicion;
    QString nig;
    QString cuantia;
    double intereses;
    double costas;
    QString reconvencion;
    double importe_reconv;

    Fase() {}

    Fase(int _id, int _id_expediente,QDate _fecha_creacion, QDate _fecha_finalizacion, QString _org_judicial, QString _procedimiento, QString _autos, QString _posicion,
            QString _nig, QString _cuantia, double _intereses, double _costas, QString _reconvencion, double _importe_reconv) :
        id(_id), id_expediente(_id_expediente), fecha_creacion(_fecha_creacion), fecha_finalizacion(_fecha_finalizacion), org_judicial(_org_judicial), procedimiento(_procedimiento),
        autos(_autos), posicion(_posicion), nig(_nig), cuantia(_cuantia), intereses(_intereses), costas(_costas), reconvencion(_reconvencion), 
        importe_reconv(_importe_reconv)
    {}

    static Fase fromJson(QJsonObject& json_fase);
    QJsonObject toJson() const;
};

#endif
