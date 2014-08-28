#ifndef NARCHIVO_H
#define NARCHIVO_H

#include <QDialog>

namespace Ui {
class nArchivo;
}

class nArchivo : public QDialog
{
    Q_OBJECT

public:
    explicit nArchivo(QWidget *parent = 0);
    ~nArchivo();

private:
    Ui::nArchivo *ui;
};

#endif // NARCHIVO_H
