#include "paintwindow.h"
#include "drawingdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PaintWindow w;
    w.setPalette(QPalette(QColor(255,255,255)));
    w.show();
    DrawingDialog * drawingDialog = w.getDrawingDialog();
    QPoint posMain = w.mapToGlobal( QPoint(0,0) );
    QSize dwSize = drawingDialog->size();
    drawingDialog->move(posMain.x() - dwSize.width() - 30, posMain.y() + w.size().height()/4 - dwSize.height()/2);
    drawingDialog->show();

    return a.exec();
}
