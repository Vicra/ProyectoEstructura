#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "filebase.h"
#include"carpeta.h"
#include "archivo.h"
#include <QDebug>

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
    void Imprimir();


};
template<class T>
int Lista<T>::Insertar(int pos,FileBase*File)
{
    if(pos > size || pos < 0)
    {
        return -1;
    }
    if(inicio==NULL)
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
void Lista<T>::Imprimir()
{
    if(inicio==NULL)
        return;
    else{
        FileBase*it=inicio;
        for(int i=0;i<size;i++)
        {
            qDebug() << it->nombre<<"\n";
            it=it->sig;
        }
    }
}
#endif // LISTA_H
