#include <iostream>
#include <QDebug>
#include <batteryInfo.h>
#include <QApplication>

using namespace std;
int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    BatteryInfo battery;
    qDebug() << "level: " << battery.level;
    qDebug() << "state: " << battery.state;
    return app.exec();
}
