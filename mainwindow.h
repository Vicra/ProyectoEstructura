#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QIcon>
#include "lista.h"
#include "carpeta.h"
#include "archivo.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Carpeta*Padre;
    Lista<FileBase*>*currentList;
    FileBase*fileCopiar;
    FileBase fCar;
    FileBase fArch;
    FileBase f;
    QString fileCopiarNombre;
    bool ok;
    explicit MainWindow(QWidget *parent = 0);
    //QIcon*carpeta = new QIcon("carpeta.png");


    ~MainWindow();

private slots:
    void updateTreeWidget();
    void updateTreeWidget2();
    void on_actionNueva_Carpeta_triggered();
    QString getPath();
    void on_actionNew_File_triggered();
    void on_actionEliminar_triggered();
    void on_searchButton_clicked();
    void on_searchLineEdit_returnPressed();
    void cambiarNombre();
    void on_actionCopiar_triggered();
    void on_actionPegar_triggered();
    void on_actionCortar_triggered();
    void on_pushButton_clicked();
    void cambiarIconos();
    void cambiarIconos2();
    void nuevoArchivo();
    void seleccionarArchivo();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
