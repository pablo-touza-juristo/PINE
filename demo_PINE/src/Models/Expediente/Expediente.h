#ifndef EXPEDIENTE_H
#define EXPEDIENTE_H

#include <QString>
#include <QDate>
#include <qcontainerfwd.h>

struct Expediente
{
    int id;
    int id_cliente;
    QString estado;
    QDate fecha_alta;
    QDate fecha_cierre;
    QString materia;
    QString descripcion;
    QString contrario;
    int year;
    int numero;
    QString autos;

    Expediente() {}
    Expediente(int _id, int _id_cliente, QString _estado, QDate _fecha_alta, QDate _fecha_cierre, QString _materia, QString _descripcion, QString _contrario, int _year, int _numero, QString _autos) :
    id(_id), id_cliente(_id_cliente), estado(_estado), fecha_alta(_fecha_alta), fecha_cierre(_fecha_cierre), materia(_materia), descripcion(_descripcion), contrario(_contrario), year(_year), numero(_numero), autos(_autos)
    {}

    Expediente(int _id, int _id_cliente, QDate _fecha_alta, QString _materia, QString _descripcion, QString _contrario, int _year, int _numero, QString _autos) :
    id(_id), id_cliente(_id_cliente), fecha_alta(_fecha_alta), materia(_materia), descripcion(_descripcion), contrario(_contrario), year(_year), numero(_numero), autos(_autos)
    {
        estado = "Vivo";
        fecha_cierre = QDate();
    }

    QString format_numero()
    {
        return (QString("%1/%2").arg(year).arg(numero));
    }

    static Expediente fromJson(QJsonObject& json_expediente);
    QJsonObject toJson() const;

};

#endif // !DEBUG
