#include <QApplication>
#include "servoguic.h"

int main(int argc, char *argv[])
{
    system("sudo ./servod");
    QApplication a(argc, argv);
    servoGuiC w;
    w.show();
    
    return a.exec();
}
