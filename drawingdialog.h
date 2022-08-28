#ifndef DRAWINGDIALOG_H
#define DRAWINGDIALOG_H

#include <QDialog>

namespace Ui {
class DrawingDialog;
}

class DrawingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DrawingDialog(QWidget *parent = 0);
    ~DrawingDialog();
  signals:
    void setupSettings(QColor penColor, int penSize);

private slots:
    void on_spinBoxR_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);

    void on_spinBoxG_valueChanged(int arg1);

    void on_spinBoxSize_valueChanged(int arg1);

    void on_pushBtnSet_clicked();

    void on_sliderR_valueChanged(int value1);

    void on_sliderG_valueChanged(int value2);

    void on_sliderB_valueChanged(int value3);

private:
    Ui::DrawingDialog *ui;
    int r,g,b;
    int penSize;
    QColor getColor();
};

#endif // DRAWINGDIALOG_H
