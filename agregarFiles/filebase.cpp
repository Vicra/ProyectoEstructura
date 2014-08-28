#include "filebase.h"

void FileBase::setNombre(QString nombre){
    this->nombre=nombre;
}
void FileBase::getNombre(){
    qDebug()<<this->nombre;
}
QString FileBase::queSoy(){
    return "soy File";
}
