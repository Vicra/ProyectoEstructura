#ifndef FILEBASE_H
#define FILEBASE_H
#include <QString>
#include <iostream>
#include <QDate>
#include <QDebug>
#include <QString>
using namespace std;

class FileBase
{
public:
    QString nombre;
    FileBase*sig;

    FileBase(){
        this->sig=NULL;
    }

    void setNombre(QString nombre);
    void getNombre();
    virtual QString queSoy();


    ~FileBase();
};

#endif // FILEBASE_H
