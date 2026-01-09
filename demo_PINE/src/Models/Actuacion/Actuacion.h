#ifndef ACTUACION_H
#define ACTUACION_H

#include <QString>
#include <QDate>

struct Actuacion
{
    int id;
    int id_fase;
    QString tipo;
    QDate fecha_creacion;
    QDate fecha_cierre;
    int duracion;
    double importe;
    QString codigo;
    QString texto;
    
    Actuacion() {}

    Actuacion(int _id, int _id_fase, QString _tipo, QDate _fecha_creacion, QDate _fecha_cierre, int _duracion, double _importe, QString _codigo, QString _texto) :
    id(_id), id_fase(_id_fase), tipo(_tipo), fecha_creacion(_fecha_creacion), fecha_cierre(_fecha_cierre), duracion(_duracion), importe(_importe), codigo(_codigo), texto(_texto)
    {}

    static Actuacion fromJson(QJsonObject& json_actuacion);
    QJsonObject toJson() const;

};

#endif // !DEBUG
