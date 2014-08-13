#ifndef LISTA_H
#define LISTA_H
#include "nodo.h"

template<class T>
class Lista
{
public:
    Nodo<T>*inicio;
    Nodo<T>*fin;
    int size;
    T value;

    Lista();

    int Insertar(int pos, T value);
    int Agregar(T value);
    int Buscar(T value);
    int Eliminar(T value);
};
template<class T>
int Lista<T>::Insertar(int pos,T value){
    if(pos > size || pos < 0)
    {
        return -1;
    }
    Nodo<T>*nuevo = new Nodo<T>(value);
    if(size == 0)
    {
        inicio = nuevo;
        fin = nuevo;
    }
    else if(pos == 0)
    {
        nuevo->sig=inicio;
        inicio=nuevo;
    }
    else if(pos == size)
    {
        fin->sig = nuevo;
        fin=nuevo;
    }
    else
    {
        Nodo<T>*it=inicio;
        for(int i=0;i<pos-1;i++)
        {
            it=it->sig;
        }
        nuevo->sig=it->sig;
        it->sig=nuevo;
    }
    size++;
    return 0;
}

template<class T>
int Lista<T>::Agregar(T value){
    return Insertar(size,value);
}

template<class T>
int Lista<T>::Buscar(T value){
    Nodo<T>*it=inicio;
        for(int i=0;i<size;i++)
        {
            if(it->value==value)
                return i;
            it=it->sig;
        }
        return-1;
}

//funcion eliminar aun no terminada
template<class T>
int Lista<T>::Eliminar(T value){
    if(inicio==NULL)
        return -1;
    if(inicio->value==value)
    {
        inicio=inicio->sig;
    }
    Nodo<T>*it=inicio;
    for(int i=0;i<size;i++)
    {
        if(it->sig->value==value)
        {
            it->sig=it->sig->sig;
        }
        it=it->sig;
    }
    return 0;
}
#endif // LISTA_H
