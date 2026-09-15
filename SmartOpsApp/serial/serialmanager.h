#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QStringList>
#include <QSerialPortInfo>
#include <QDebug>
class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);
    QStringList availablePorts() const;
    bool openSerial(const QString &portName,qint32 baudRate);
    void closeSerial();
    bool isOpen() const;

private:
    // SerialManager 持有一个 QSerialPort 对象
    // 将 this 设置为其父对象，SerialManager 销毁时
    // Qt 会自动销毁 m_serialPort
    QSerialPort *m_serialPort;

signals:
};

#endif // SERIALMANAGER_H
