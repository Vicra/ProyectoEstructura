#ifndef CARPETA_H
#define CARPETA_H
#include "filebase.h"

class Carpeta: public FileBase
{
public:
    Carpeta(FileBase *padre){}
    QString queSoy();
};

#endif // CARPETA_H
