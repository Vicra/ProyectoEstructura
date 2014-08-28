#include <QCoreApplication>
#include "filebase.h"
#include "carpeta.h"
#include "archivo.h"
#include "lista.h"
#include <iostream>
#include <QString>
#include <QDebug>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Lista<FileBase*>*lista= new  Lista<FileBase*>;

    FileBase*nuevo = new Archivo();
    nuevo->setNombre("archivo1");

    FileBase*nuevo2 = new Carpeta();
    nuevo2->setNombre("carpeta2");

    FileBase*nuevo3 = new Archivo();
    nuevo3->setNombre("archivo3");

    lista->Insertar(0,nuevo);
    lista->Insertar(1,nuevo2);
    lista->Insertar(1,nuevo3);
    lista->Imprimir();

    return a.exec();
}
