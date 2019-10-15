#include "servoguic.h"
#include "ui_servoguic.h"
#include "servoControlC.cxx"
#include <QString>
#include <thread>
#include <iostream>
servoGuiC::servoGuiC(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::servoGuiC)
{
    ui->setupUi(this);
}
//using namespace std;




servoGuiC::~servoGuiC()
{
    delete ui;
}





void servoGuiC::on_pushButton_clicked()//Right
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());

    ui ->label_5 ->setNum(delay_period);



    std::thread td2(ledOn);
    std::thread td1([&] {right();});
    td1.join();
    td2.join();



   // right();
}

void servoGuiC::on_pushButton_3_clicked()
{
    //this->close();
    cservod();
}

void servoGuiC::on_pushButton_2_clicked()
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());


    ui ->label_5 ->setNum(delay_period);


    std::thread td2(ledOff);
    std::thread td1([&] {left();});
    td1.join();
    td2.join();


   // left();


}

void servoGuiC::on_pushButton_4_clicked()
{
    float delay_period=atoi(ui ->lineEdit ->text().toStdString().c_str());

    ui ->label_5 ->setNum(delay_period);
    center();
}
