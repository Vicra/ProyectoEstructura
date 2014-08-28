#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "filebase.h"
#include "narchivo.h"

class Archivo:public FileBase
{
public:
    QString texto;
    nArchivo*n;
    Archivo(FileBase*padre){
        this->padre=padre;
        this->tamano="5 kb";
        n=new nArchivo();
    }
    QString queSoy();
    void setTexto(QString texto);
    QString getTexto();

};

#endif // ARCHIVO_H
