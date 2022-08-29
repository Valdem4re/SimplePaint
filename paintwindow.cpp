#include "paintwindow.h"
#include "ui_paintwindow.h"

#include <QMessageBox>
#include <QPainter>
#include <QPixmap>
#include <QFile>
#include <QGraphicsPixmapItem>
#include <QDataStream>
#include <QImage>
#include <QFileDialog>


PaintWindow::PaintWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PaintWindow)
{
    ui->setupUi(this);


    this->setCursor(QCursor(QPixmap(":/images/textures/pencil.png").scaled(32,32,Qt::KeepAspectRatio)));

    m_linePen.setColor(QColor(0,0,0));
    m_linePen.setWidth(1);
    m_bDrawing = false;
}

PaintWindow::~PaintWindow()
{
    delete ui;  delete m_pDrawingDialog;
}

void PaintWindow::setupSettings(QColor _color, int _size)
{
    m_linePen.setColor(_color);
    m_linePen.setWidth(_size);
}

void PaintWindow::mousePressEvent(QMouseEvent* event)
{ m_bDrawing = true;
  m_P0 = event->pos(); m_P1 = m_P0;
  TPolyline polyline;
  polyline.pen = m_linePen;
  m_curve<< polyline;
}

void PaintWindow::mouseMoveEvent(QMouseEvent * event)
{  if (!m_bDrawing) return;
    m_P0 = m_P1; m_P1 = event->pos();
    m_curve.last().segments << qMakePair(m_P0,m_P1);
    update();
}

void PaintWindow::mouseReleaseEvent(QMouseEvent *event)
{   Q_UNUSED(event); //Предотвращает предупреждение о неиспользуемом параметре
    m_bDrawing = false;
}

void PaintWindow::paintEvent(QPaintEvent *event)
{   Q_UNUSED(event); //Предотвращает предупреждение о неиспользуемом параметре
    QPainter painter(this);
    TSegmentsList::const_iterator segmListIT;
    m_constcurveIT = m_curve.cbegin();
    while(m_constcurveIT != m_curve.cend())
    { painter.setPen(m_constcurveIT->pen);
      segmListIT = m_constcurveIT->segments.cbegin();
      while(segmListIT != m_constcurveIT->segments.cend())
      { painter.drawLine(segmListIT->first,segmListIT->second );
        ++segmListIT;
      }
      ++m_constcurveIT;
    }
}



void PaintWindow::on_actionSave_triggered()
{

//    QPixmap image = ui->centralWidget->grab();
//    QString fileName = QFileDialog::getSaveFileName(this, QString::fromLocal8Bit("Save image"), "",QString::fromLocal8Bit("(*.png)"));
//    QFile imageFile(fileName);
//    imageFile.open(QIODevice::WriteOnly);
//    QDataStream stream(&imageFile);
//    stream << image;
//    imageFile.close();

    QPixmap screen = ui->centralWidget->grab();
      QString fileName = QFileDialog::getSaveFileName(0, "Сохранить как...", QDir::currentPath(), "All types(*.*);;PNG (*.png);;JPG (*jpeg *jpg);; BMP (*.bmp)");
      if (fileName.isNull())
        return;
      screen.save(fileName,0,100);

}

void PaintWindow::on_actionColor_Settings_triggered()
{
    if(m_pDrawingDialog == nullptr){
        m_pDrawingDialog = new DrawingDialog(this);
        connect(m_pDrawingDialog,SIGNAL(setupSettings(QColor,int)),this,SLOT(setupSettings(QColor,int)));
        connect(m_pDrawingDialog, SIGNAL(closeDrawingDialog()), this, SLOT(slotCloseDrawingDialog()));
        m_pDrawingDialog->show();
    }
    else{
        QMessageBox::warning(this,"Warning", "Color settings are already open.");
    }
}

void PaintWindow::slotCloseDrawingDialog()
{
    delete m_pDrawingDialog;
    m_pDrawingDialog = nullptr;
}

