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


}

QStringList SerialManager::availablePorts() const
{
    QStringList portNames;

    const auto ports = QSerialPortInfo::availablePorts();

    for(auto &port:ports){
        portNames.append(port.portName());
    }

    return portNames;
}

bool SerialManager::openSerial(const QString &portName, qint32 baudRate)
{
    if(m_serialPort->isOpen()){
        m_serialPort->close();
    }
    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate);

    m_serialPort->setDataBits(QSerialPort::Data8);
    m_serialPort->setParity(QSerialPort::NoParity);
    m_serialPort->setStopBits(QSerialPort::OneStop);
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);

    if(m_serialPort->open(QIODevice::ReadWrite)){
        qDebug()<<"串口打开成功："
                 <<portName
                 <<baudRate;
        return true;
    }else{
        qDebug()<<"串口打开失败："
                 <<m_serialPort->errorString();
        return false;
    }


}

void SerialManager::closeSerial()
{
    m_serialPort->close();
}

bool SerialManager::isOpen() const
{
    return m_serialPort->isOpen();
}

