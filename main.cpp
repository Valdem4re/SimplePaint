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


    return a.exec();
}
