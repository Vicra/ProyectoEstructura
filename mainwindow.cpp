#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtGui>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QList>
#include "narchivo.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Padre=new Carpeta(NULL);
    Padre->setNombre("C:");
    ui->pathLine->setText(Padre->nombre+"\\");
    ui->treeWidget->setColumnCount(1);
    ui->treeWidget->setFixedWidth(200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::getPath(){
     QString pathline;
     QStringList list;
     ok=true;

     pathline=ui->pathLine->text();
     list=pathline.split("\\");
     QString finPath= list.at(list.length()-2);
     return finPath;
}

void MainWindow::updateTreeWidget(){
    ui->treeWidget->clear();
    QList<QTreeWidgetItem *> items;
    QTreeWidgetItem*itm;
    QIcon carpeta(":/Images/carpeta.png");

    for(int i=0;i<Padre->lista->size;i++)
    {
        itm=new QTreeWidgetItem();
        itm->setText(0,Padre->lista->getNombre(i));

        FileBase*file=Padre->lista->getFile(i);
        if(file->queSoy()=="carpeta"){
            itm->setIcon(0,carpeta);
            items.append(itm);
        }
    }
    ui->treeWidget->insertTopLevelItems(0,items);
}
void MainWindow::updateTreeWidget2(){
    ui->treeWidget_2->clear();
    ui->treeWidget_2->setColumnCount(1);
    QList<QTreeWidgetItem *> items;
    QTreeWidgetItem*itm;

    QIcon archivo(":/Images/archivo.png");
    QIcon carpeta(":/Images/carpeta.png");

    for(int i=0;i<Padre->lista->size;i++)
    {
        itm=new QTreeWidgetItem();
        itm->setText(0,Padre->lista->getNombre(i));

        FileBase*file=Padre->lista->getFile(i);
        if(file->queSoy()=="carpeta"){
            itm->setIcon(0,carpeta);
            items.append(itm);
        }
    }
    for(int i=0;i<Padre->lista->size;i++)
    {
        itm=new QTreeWidgetItem();
        itm->setText(0,Padre->lista->getNombre(i)+".txt");

        FileBase*file=Padre->lista->getFile(i);
        if(file->queSoy()=="archivo"){
            itm->setIcon(0,archivo);
            items.append(itm);
        }
    }
    ui->treeWidget_2->addTopLevelItems(items);
    ui->treeWidget_2->setIconSize(QSize(45,45));
}
void MainWindow::on_actionNueva_Carpeta_triggered()
{
    bool ok;
    QString name=QInputDialog::getText(this,"Crear Carpeta","Nombre:",
                                       QLineEdit::Normal,QString("NuevaCarpeta"), &ok);
    if(name.isEmpty())
        return;
    int p=Padre->lista->Buscar(name);
    if(p<0||p>Padre->lista->size){
        FileBase*nuevo = new Carpeta(Padre);
        nuevo->setNombre(name);
        Padre->lista->Agregar(nuevo);
        updateTreeWidget();
        updateTreeWidget2();
    }else if(p>=0||p<=Padre->lista->size)
    {
        //on_actionCopiar_triggered();
    }

}
void MainWindow::on_actionNew_File_triggered()
{
    bool ok;
    QString name=QInputDialog::getText(this,"Crear Archivo","Nombre:",
                                       QLineEdit::Normal,QString("file"), &ok);
    if(name.isEmpty())
        return;
    FileBase*nuevo = new Archivo(Padre);
    nuevo->setNombre(name);
    Padre->lista->Agregar(nuevo);
    nuevoArchivo();
    updateTreeWidget();
    updateTreeWidget2();
}
void MainWindow::nuevoArchivo(){
    nArchivo*g= new nArchivo(this);
    g->show();
}
void MainWindow::seleccionarArchivo(){
    QTreeWidgetItem*itm=ui->treeWidget_2->currentItem();
    QString nombre=itm->text(0);
    int pos=Padre->lista->Buscar(nombre);
    FileBase*file=Padre->lista->getFile(pos);

    if(ui->treeWidget_2->isItemSelected(itm)){
        if(file->queSoy()=="archivo"){
            nuevoArchivo();
        }
    }
}

void MainWindow::on_actionEliminar_triggered()
{

   QTreeWidgetItem*itm=ui->treeWidget_2->currentItem();
   if(ui->treeWidget_2->isItemSelected(itm)){
           QString nombre=itm->text(0);
           QStringList list;
           list=nombre.split(".");
           Padre->lista->Eliminar(list.at(0));
           updateTreeWidget();
           updateTreeWidget2();
   }
}
void MainWindow::on_searchButton_clicked()
{
    QString nombre=ui->searchLineEdit->text();
    if(nombre.isEmpty()){
        return;
    }
    else{
        int pos=Padre->lista->Buscar(nombre);
        if(pos>=0 && pos<=Padre->lista->size)
        {
            ui->treeWidget_2->clear();
            QTreeWidgetItem*itm;
            QIcon archivo(":/Images/archivo.png");
            QIcon carpeta(":/Images/carpeta.png");

            itm=new QTreeWidgetItem();
            itm->setText(0,Padre->lista->getNombre(pos));

            FileBase*file=Padre->lista->getFile(pos);
            if(file->queSoy()=="archivo"){
                itm->setIcon(0,archivo);
                itm->setText(0,Padre->lista->getNombre(pos)+".txt");
            }

            else{
                itm->setIcon(0,carpeta);
            }
            ui->treeWidget_2->addTopLevelItem(itm);
            ui->treeWidget_2->setColumnCount(1);
            ui->treeWidget_2->setIconSize(QSize(45,45));
        }

    }

}
void MainWindow::on_searchLineEdit_returnPressed()
{
    on_searchButton_clicked();
}

//TRABAJAR FUNCIONES COPIAR PEGAR Y CORTAR
void MainWindow::on_actionCopiar_triggered()
{
    QTreeWidgetItem*itm=ui->treeWidget_2->currentItem();
    if(ui->treeWidget_2->isItemSelected(itm)){
            fileCopiarNombre=itm->text(0);
            int pos=Padre->lista->Buscar(fileCopiarNombre);
            fileCopiar=Padre->lista->getFile(pos);
            qDebug()<<fileCopiar->queSoy();
    }
}
void MainWindow::on_actionPegar_triggered()
{
    fileCopiar->setNombre(fileCopiarNombre);
    if(fileCopiar->queSoy()=="archivo"){
       //fArch = new Archivo(Padre);
       fArch=*fileCopiar;
       fileCopiar=&fArch;
   }else if(fileCopiar->queSoy()=="carpeta"){
       //fCar = new Carpeta(Padre);
       fCar=*fileCopiar;
       fileCopiar=&fCar;
   }
    fileCopiar->setNombre(fileCopiarNombre+"-copia1");
    Padre->lista->Agregar(fileCopiar);
    f=*fileCopiar;
    fileCopiar=&f;
    fileCopiar->setNombre(fileCopiarNombre+"-copia1");
    qDebug()<<fileCopiar->queSoy();
    Padre->lista->Imprimir();
    qDebug()<<"fila 3";
    updateTreeWidget();
    qDebug()<<"fila 4";
    updateTreeWidget2();
    qDebug()<<"fila 5";

}
void MainWindow::cambiarNombre(){
    FileBase*file;
    file=Padre->lista->getFile(Padre->lista->size-1);
    file->setNombre(file->getNombre()+"copia1");
}
void MainWindow::on_actionCortar_triggered()
{
    QTreeWidgetItem*itm=ui->treeWidget_2->currentItem();
    if(ui->treeWidget_2->isItemSelected(itm)){
            fileCopiarNombre=itm->text(0);
            Padre->lista->Eliminar(fileCopiarNombre);
            updateTreeWidget();
            updateTreeWidget2();
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ok==true)
        cambiarIconos();
    else
        cambiarIconos2();
}
void MainWindow::cambiarIconos(){
    ui->treeWidget_2->clear();
    ui->treeWidget_2->setColumnCount(3);
    ui->treeWidget_2->setColumnWidth(0,150);

    QList<QTreeWidgetItem *> items;
    QTreeWidgetItem*itm;

    QIcon archivo(":/Images/archivo.png");
    QIcon carpeta(":/Images/carpeta.png");

    for(int i=0;i<Padre->lista->size;i++)
    {
        FileBase*file=Padre->lista->getFile(i);
        itm=new QTreeWidgetItem();
        itm->setText(0,file->nombre);
        itm->setText(1,file->date);
        itm->setText(2,file->tamano);

        if(file->queSoy()=="carpeta"){
            itm->setIcon(0,carpeta);
            items.append(itm);
        }
    }
    for(int i=0;i<Padre->lista->size;i++)
    {
        FileBase*file=Padre->lista->getFile(i);
        itm=new QTreeWidgetItem();
        itm->setText(0,file->nombre);
        itm->setText(1,file->date);
        itm->setText(2,file->tamano);
        if(file->queSoy()=="archivo"){
            itm->setIcon(0,archivo);
            items.append(itm);
        }
    }
    ui->treeWidget_2->addTopLevelItems(items);
    ui->treeWidget_2->setIconSize(QSize(20,20));
    ok=false;

}
void MainWindow::cambiarIconos2(){
    updateTreeWidget2();
    ok=true;
}


