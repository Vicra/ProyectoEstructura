#ifndef NODO_H
#define NODO_H
#include <iostream>

using namespace std;
//agregando comentario
template<class T>
class Nodo
{
public:
    Nodo<T>*sig;
    T value;

    Nodo(T value);
};

#endif // NODO_H
