moc batteryInfo.h > moc_batteryInfo.cpp
g++ -o battery.x batteryInfo.cpp moc_batteryInfo.cpp battery.cpp -I/usr/include/qt5/QtCore -I/usr/include/qt5/QtWidgets  -I/usr/include/qt5 -I. -fPIC -lcontextkit-statefs-qt5 -lQt5Widgets -lQt5Core

