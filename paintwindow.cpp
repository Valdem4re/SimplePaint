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
    drawingDialog = new DrawingDialog(this);

    this->setCursor(QCursor(QPixmap(":/images/textures/pencil.png").scaled(32,32,Qt::KeepAspectRatio)));

    connect(drawingDialog,SIGNAL(setupSettings(QColor,int)),this,SLOT(setupSettings(QColor,int)));

    linePen.setColor(QColor(0,0,0));
    linePen.setWidth(1);
    Drawing = false;
}

PaintWindow::~PaintWindow()
{
    delete ui;  delete drawingDialog;
}

void PaintWindow::setupSettings(QColor color, int size)
{
    linePen.setColor(color);
    linePen.setWidth(size);
}

void PaintWindow::mousePressEvent(QMouseEvent* event)
{ Drawing = true;
  P0 = event->pos(); P1=P0;
  TPolyline polyline;
  polyline.pen = linePen;
  curve<< polyline;
}

void PaintWindow::mouseMoveEvent(QMouseEvent * event)
{  if (!Drawing) return;
    P0 = P1; P1 = event->pos();
    curve.last().segments << qMakePair(P0,P1);
    update();
}

void PaintWindow::mouseReleaseEvent(QMouseEvent *event)
{   Q_UNUSED(event); //Предотвращает предупреждение о неиспользуемом параметре
    Drawing = false;
}

void PaintWindow::paintEvent(QPaintEvent *event)
{   Q_UNUSED(event); //Предотвращает предупреждение о неиспользуемом параметре
    QPainter painter(this);
    TSegmentsList::const_iterator segmListIT;
    constcurveIT = curve.cbegin();
    while(constcurveIT != curve.cend())
    { painter.setPen(constcurveIT->pen);
      segmListIT = constcurveIT->segments.cbegin();
      while(segmListIT != constcurveIT->segments.cend())
      { painter.drawLine(segmListIT->first,segmListIT->second );
        ++segmListIT;
      }
      ++constcurveIT;
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

