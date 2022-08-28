#include "drawingdialog.h"
#include "ui_drawingdialog.h"

DrawingDialog::DrawingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DrawingDialog)
{
    ui->setupUi(this);
    m_Red = ui->spinBoxR->value();
    m_Green = ui->spinBoxR->value();
    m_Blue = ui->spinBoxR->value();
    m_penSize = ui->spinBoxSize->value();
}

DrawingDialog::~DrawingDialog()
{
    delete ui;
}
QColor DrawingDialog::getColor()
{ return QColor(m_Red, m_Green, m_Blue);
}

void DrawingDialog::on_spinBoxR_valueChanged(int arg1)
{
    m_Red = arg1;
    ui->sliderR->setValue(m_Red);
}

void DrawingDialog::on_spinBoxB_valueChanged(int arg1)
{
    m_Green = arg1;
    ui->sliderB->setValue(m_Blue);

}

void DrawingDialog::on_spinBoxG_valueChanged(int arg1)
{
    m_Green = arg1;
    ui->sliderG->setValue(m_Green);

}

void DrawingDialog::on_spinBoxSize_valueChanged(int arg1)
{
    m_penSize = arg1;

}

void DrawingDialog::on_pushBtnSet_clicked()
{
    QColor col = getColor();
    emit setupSettings(col, m_penSize); //заказ толстого пера
    if (this->isModal()) this->setHidden(true);
}

void DrawingDialog::on_sliderR_valueChanged(int value1)
{
    m_Red = value1;
    ui->spinBoxR->setValue(value1);
}

void DrawingDialog::on_sliderG_valueChanged(int value2)
{
    m_Green = value2;
    ui->spinBoxG->setValue(value2);
}


void DrawingDialog::on_sliderB_valueChanged(int value3)
{
    m_Blue = value3;
    ui->spinBoxB->setValue(value3);
}

