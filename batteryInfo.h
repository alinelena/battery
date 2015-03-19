#ifndef BATTERYNIFO_H
#define BATTERYINFO_H

#include <QObject>
#include <QString>
class ContextProperty;

class BatteryInfo : public QObject {
    Q_OBJECT

public:
    BatteryInfo(QObject *parent = NULL);
    virtual ~BatteryInfo();
  enum State {                                                                                                                                 
     Charging =0 ,
     Discharging,
     Full,
     Unknown
  };
    int level;
    State state;
public slots:
    void initBattery();

private slots:
    void onPropertyChanged();

private:
    int getLevel() const;
    State  getState() const;

    ContextProperty *batteryLevel;
    ContextProperty *batteryState;

};

#endif
