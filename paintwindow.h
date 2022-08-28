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
    {return m_pDrawingDialog;}

    void setConstcurveIT(const TPicture::const_iterator &_newConstcurveIT);

private slots:

    void setupSettings(QColor _color, int _size);

    void on_actionSave_triggered();

protected:

     void mousePressEvent(QMouseEvent* event);

     void mouseMoveEvent(QMouseEvent * event);

     void mouseReleaseEvent(QMouseEvent *event);

     void paintEvent(QPaintEvent *event);

private:
    Ui::PaintWindow *ui;

    DrawingDialog * m_pDrawingDialog;

    bool m_bDrawing;

    QPen m_linePen;

    QPoint m_P0, m_P1;

    TPicture m_curve;

    TPicture::const_iterator m_constcurveIT;
};

#endif // MINIPAINTWINDOW_H
