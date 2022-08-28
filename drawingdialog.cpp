#include "drawingdialog.h"
#include "ui_drawingdialog.h"

DrawingDialog::DrawingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawingDialog)
{
    ui->setupUi(this);
    r = ui->spinBoxR->value();
    g = ui->spinBoxR->value();
    b = ui->spinBoxR->value();
    penSize = ui->spinBoxSize->value();
}

DrawingDialog::~DrawingDialog()
{
    delete ui;
}
QColor DrawingDialog::getColor()
{ return QColor(r,g,b);
}

void DrawingDialog::on_spinBoxR_valueChanged(int arg1)
{
    r = arg1;
    ui->sliderR->setValue(r);
}

void DrawingDialog::on_spinBoxB_valueChanged(int arg1)
{
    b = arg1;
    ui->sliderB->setValue(b);

}

void DrawingDialog::on_spinBoxG_valueChanged(int arg1)
{
    g = arg1;
    ui->sliderG->setValue(g);

}

void DrawingDialog::on_spinBoxSize_valueChanged(int arg1)
{
    penSize = arg1;

}

void DrawingDialog::on_pushBtnSet_clicked()
{   QColor col = getColor();
    emit setupSettings(col,penSize); //заказ толстого пера
    if (this->isModal()) this->setHidden(true);
}

void DrawingDialog::on_sliderR_valueChanged(int value1)
{
    r = value1;
    ui->spinBoxR->setValue(value1);
}

void DrawingDialog::on_sliderG_valueChanged(int value2)
{
    g = value2;
    ui->spinBoxG->setValue(value2);
}


void DrawingDialog::on_sliderB_valueChanged(int value3)
{
    b = value3;
    ui->spinBoxB->setValue(value3);
}

