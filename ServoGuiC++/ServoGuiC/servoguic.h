#ifndef SERVOGUIC_H
#define SERVOGUIC_H

#include <QMainWindow>

namespace Ui {
class servoGuiC;
}

class servoGuiC : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit servoGuiC(QWidget *parent = 0);
    ~servoGuiC();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    int right();

    int left();

    int center();

private:
    Ui::servoGuiC *ui;
};

#endif // SERVOGUIC_H
