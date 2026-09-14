#include "serialmanager.h"

SerialManager::SerialManager(QObject *parent)
    : QObject{parent}
{
    /*
    外部 parent
       ↓
    SerialManager
       ↓
    QSerialPort
    */
    m_serialPort = new QSerialPort(this);

    QStringList portNames;

    const auto ports = QSerialPortInfo::availablePorts();

    for(auto &port:ports){
        portNames.append(port.portName());
    }
}