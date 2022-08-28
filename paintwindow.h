#ifndef MINIPAINTWINDOW_H
#define MINIPAINTWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPen>
#include <QPair>
#include <QList>
//#include <QLinkedList>
#include "drawingdialog.h"

namespace Ui {
class PaintWindow;
}
//Дополнительные типы
using TSegment = QPair<QPoint, QPoint>;//Отрезок
using TSegmentsList = QList<TSegment>;//Линия из отрезков
using TPolyline = struct { QPen pen; TSegmentsList segments;};
using TPicture = QList<TPolyline>; //Набор линий из отрезков


class PaintWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PaintWindow(QWidget *parent = 0);
    ~PaintWindow();
    DrawingDialog * getDrawingDialog()
    {return drawingDialog;}
private slots:
    void setupSettings(QColor color, int size);
    void on_actionSave_triggered();

protected:
     void mousePressEvent(QMouseEvent* event);
     void mouseMoveEvent(QMouseEvent * event);
     void mouseReleaseEvent(QMouseEvent *event);
     void paintEvent(QPaintEvent *event);

private:
    Ui::PaintWindow *ui;
    DrawingDialog * drawingDialog;
    bool Drawing;
    QPen linePen;
    QPoint P0,P1;

    TPicture curve;
    TPicture::const_iterator constcurveIT;
};

#endif // MINIPAINTWINDOW_H
