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
    void setupSettings(QColor _penColor, int _penSize);

private slots:
    void on_spinBoxR_valueChanged(int arg1);

    void on_spinBoxB_valueChanged(int arg1);

    void on_spinBoxG_valueChanged(int arg1);

    void on_spinBoxSize_valueChanged(int arg1);

    void on_pushBtnSet_clicked();

    void on_sliderR_valueChanged(int value1);

    void on_sliderG_valueChanged(int value2);

    void on_sliderB_valueChanged(int value3);

    void on_pushBtnEraser_clicked(bool checked);

private:
    Ui::DrawingDialog *ui;
    int m_Red, m_Green, m_Blue;

    int m_penSize;

    QColor getColor();
};

#endif // DRAWINGDIALOG_H
