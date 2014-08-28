#include "filebase.h"

void FileBase::setNombre(QString nombre){
    this->nombre=nombre;
}
QString FileBase::getNombre(){
    return this->nombre;
}
QString FileBase::queSoy(){
    return "file";
}
