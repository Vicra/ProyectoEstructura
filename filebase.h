#ifndef FILEBASE_H
#define FILEBASE_H
#include <QString>
#include <iostream>
#include <QDate>
#include <QDebug>
#include <QString>
#include <QTime>

using namespace std;

class FileBase
{
public:
    QString nombre;
    QString tamano;
    QDate fecha;
    QString date;

    FileBase*sig;
    FileBase*padre;

    FileBase(){
        this->sig=NULL;
        this->tamano="0 kb";
        this->date=fecha.currentDate().toString();
    }

    void setNombre(QString nombre);
    QString getNombre();
    virtual QString queSoy();
    virtual void setTexto(QString l){
        qDebug()<<l;
    }

    ~FileBase(){}
};



#endif // FILEBASE_H
