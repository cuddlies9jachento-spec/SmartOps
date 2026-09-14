#ifndef SERIALMANAGER_H
#define SERIALMANAGER_H

#include <QObject>
#include <QSerialPort>
#include <QStringList>
#include <QSerialPortInfo>
class SerialManager : public QObject
{
    Q_OBJECT
public:
    explicit SerialManager(QObject *parent = nullptr);
private:
    /*SerialManager对象自己的成员变量
    使用指针是为了继承父对象QSerialPort，后续serialManager销毁就会自动销毁了
    */
    QSerialPort *m_serialPort;

signals:
};

#endif // SERIALMANAGER_H
