#include "drawingdialog.h"
#include "ui_drawingdialog.h"
#include <QPalette>

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
{
    return QColor(m_Red, m_Green, m_Blue);
}

void DrawingDialog::applySettings()
{
    QColor col = getColor();
    emit setupSettings(col, m_penSize); //заказ толстого пера
    if (this->isModal()) this->setHidden(true);
}

void DrawingDialog::on_spinBoxR_valueChanged(int arg1)
{
    m_Red = arg1;
    ui->sliderR->setValue(m_Red);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));


}

void DrawingDialog::on_spinBoxB_valueChanged(int arg1)
{
    m_Blue = arg1;
    ui->sliderB->setValue(m_Blue);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));
//    QColor col = getColor();
//    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));
//    emit setupSettings(col, m_penSize); //заказ толстого пера
//    if (this->isModal()) this->setHidden(true);

}

void DrawingDialog::on_spinBoxG_valueChanged(int arg1)
{
    m_Green = arg1;
    ui->sliderG->setValue(m_Green);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));

}

void DrawingDialog::on_spinBoxSize_valueChanged(int arg1)
{
    m_penSize = arg1;
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));

}

//void DrawingDialog::on_pushBtnSet_clicked()
//{
//    QColor col = getColor();
//    emit setupSettings(col, m_penSize); //заказ толстого пера
//    if (this->isModal()) this->setHidden(true);
//}

void DrawingDialog::on_sliderR_valueChanged(int value1)
{
    m_Red = value1;
    ui->spinBoxR->setValue(value1);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));
}

void DrawingDialog::on_sliderG_valueChanged(int value2)
{
    m_Green = value2;
    ui->spinBoxG->setValue(value2);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));
}


void DrawingDialog::on_sliderB_valueChanged(int value3)
{
    m_Blue = value3;
    ui->spinBoxB->setValue(value3);
    applySettings();
    QColor col = getColor();
    ui->label->setStyleSheet(QString("color:%1").arg(col.name()));
}



void DrawingDialog::on_pushBtnEraser_clicked(bool checked)
{
    static int R = ui->spinBoxR->value();
    static int G = ui->spinBoxG->value();
    static int B = ui->spinBoxB->value();
    static QColor lastColor;
    if(checked){
        ui->spinBoxR->setValue(255);
        ui->spinBoxG->setValue(255);
        ui->spinBoxB->setValue(255);
        QColor color = getColor();
        emit setupSettings(color, m_penSize);
        ui->label->setStyleSheet(QString("color:%1").arg(lastColor.name()));
        ui->pushBtnEraser->setChecked(true);


    }
    else{
        ui->spinBoxR->setValue(R);
        ui->spinBoxG->setValue(G);
        ui->spinBoxB->setValue(B);
        applySettings();
        ui->pushBtnEraser->setChecked(false);
    }
}


void DrawingDialog::on_DrawingDialog_rejected()
{
    emit closeDrawingDialog();
}

