#include "archivo.h"

QString Archivo::queSoy(){
    return "archivo";
}
void Archivo::setTexto(QString texto){
    this->texto=texto;
}
QString Archivo::getTexto(){
    return this->texto;
}
