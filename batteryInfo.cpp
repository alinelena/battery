#include <QCoreApplication>
#include <QDebug>
#include "batteryInfo.h"
#include <contextproperty.h>


static inline QString propertyString(ContextProperty *p)
{
   QString res(p->value().toString().trimmed());
   return res;
}

BatteryInfo::BatteryInfo(QObject *parent) :
    QObject(parent),
    level(-1),
    state(Unknown),
    batteryLevel(new ContextProperty("Battery.ChargePercentage", this)),
    batteryState(new ContextProperty("Battery.State", this))
{
    batteryLevel->subscribe();
    batteryState->subscribe();
    batteryLevel->waitForSubscription(true);
    level=getLevel();
    state=getState();
    connect(batteryLevel, SIGNAL(valueChanged()), this, SLOT(onPropertyChanged()));
    connect(batteryState, SIGNAL(valueChanged()), this, SLOT(onPropertyChanged()));
}

BatteryInfo::~BatteryInfo()
{
  batteryLevel->unsubscribe();
  batteryState->unsubscribe();
  delete batteryLevel;
  delete batteryState;
}

void BatteryInfo::init()
{
    onPropertyChanged();
}

void BatteryInfo::onPropertyChanged()
{
  level=getLevel();
  state=getState();
  qDebug()<<"level: "<<level<<" state: "<<state;
}

int BatteryInfo::getLevel() const
{
    return batteryLevel->value().toInt();
}

BatteryInfo::State BatteryInfo::getState() const
{
    QString res(batteryState->value().toString().trimmed());
    if (res=="charging"){
       return Charging;
    }else if(res=="discharging"){
       return Discharging;
    }else if(res=="full"){
       return Full;
    }else {
      return Unknown;
    }
}
