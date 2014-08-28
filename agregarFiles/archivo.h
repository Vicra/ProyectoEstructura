#ifndef ARCHIVO_H
#define ARCHIVO_H
#include "filebase.h"

class Archivo:public FileBase
{
public:
    Archivo(){}
    virtual QString queSoy();
};

#endif // ARCHIVO_H
