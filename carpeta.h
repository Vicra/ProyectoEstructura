#ifndef CARPETA_H
#define CARPETA_H
#include "filebase.h"
#include "lista.h"


class Carpeta: public FileBase
{
public:
    Lista<FileBase*>*lista;
    Carpeta(FileBase*padre){
        this->padre=padre;
        lista = new Lista<FileBase*>();
    }
    QString queSoy();
};

#endif // CARPETA_H
