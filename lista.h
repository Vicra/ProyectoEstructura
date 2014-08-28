#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "filebase.h"
#include "archivo.h"

#include <qdebug.h>

using namespace std;

template<class T>
class Lista
{
public:
    T inicio;
    T fin;
    int size;

    Lista(){
        inicio=NULL;
        fin=NULL;
        size=0;
    }
    int Insertar(int pos,FileBase*File);
    int Agregar(FileBase*File);
    int EliminarPos(int pos);
    int Buscar(QString nombre);
    int Buscar(int pos);
    int Eliminar(QString nombre);

    void Imprimir();
    QString getNombre(int pos);
    FileBase*getFile(int pos);

};
template<class T>
int Lista<T>::Insertar(int pos,FileBase*File)
{
    if(pos > size || pos < 0)
    {
        return -1;
    }

    //File = new FileBase();
    //File->setNombre(nombre);
    if(size == 0)
    {
        inicio = File;
        fin = File;
    }
    else if(pos == 0)
    {
        File->sig=inicio;
        inicio=File;
    }
    else if(pos == size)
    {
        fin->sig = File;
        fin=File;
    }
    else
    {
        FileBase *it=inicio;
        for(int i=0;i<pos-1;i++)
        {
            it=it->sig;
        }
        File->sig=it->sig;
        it->sig=File;
    }
    size++;
    return 0;
}

template<class T>
int Lista<T>::Agregar(FileBase*File){
    return Insertar(size,File);
}
template<class T>
void Lista<T>::Imprimir(){
    if(inicio ==  NULL)
        return;
    FileBase*it=inicio;
    for(int i=0;i<size;i++)
    {
        qDebug() << it->nombre;
        it=it->sig;
    }
}

template<class T>
QString Lista<T>::getNombre(int pos)
{
    if(inicio==NULL){
        return "";
    }
    if(pos<0 || pos >size)
        return "";
    else{
        FileBase*it=inicio;
        for(int i=0;i<pos;i++)
        {
            it=it->sig;
        }
        return it->nombre;
    }
}
template<class T>
FileBase *Lista<T>::getFile(int pos)
{
    if(pos<0 || pos >size)
        return NULL;
    if(inicio==NULL)
        return NULL;
    else{
        FileBase*it=inicio;
        for(int i=0;i<pos;i++)
        {
            it=it->sig;
        }
        return it;
    }
}

template<class T>
int Lista<T>::EliminarPos(int pos){
    if(pos<0||pos>size)
        return -1;
    if(inicio==NULL)
        return -1;
    if(pos==0)
        inicio=inicio->sig;
    else{
        FileBase*it=inicio;
        for(int i=0; i<pos-1;i++)
            it=it->sig;
        if(pos!=size-1)
            it->sig=it->sig->sig;
        else
            {
                fin=it;
                fin->sig=NULL;
            }
    }
    size--;
    return 0;
}

template <class T>
int Lista<T>::Eliminar(QString nombre){
    int pos = Buscar(nombre);
    return EliminarPos(pos);
}

template <class T>
int Lista<T>::Buscar(QString nombre){
    FileBase*it=inicio;
    for(int i=0;i<size;i++)
    {
        if(it->nombre==nombre)
            return i;
        it=it->sig;
    }
    return-1;
}

#endif // LISTA_H
