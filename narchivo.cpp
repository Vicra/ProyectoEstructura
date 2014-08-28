#include "narchivo.h"
#include "ui_narchivo.h"

nArchivo::nArchivo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nArchivo)
{
    ui->setupUi(this);
}

nArchivo::~nArchivo()
{
    delete ui;
}
