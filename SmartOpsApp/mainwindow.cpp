#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include "serial/serialmanager.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_serialManager(new SerialManager(this))
{
    ui->setupUi(this);
    QStringList ports = m_serialManager->availablePorts();
    ui->comboPort->addItems(ports);
    qDebug() << "检测到的串口：" << ports;
    // QString portName = ui->comboPort->currentText();
    // bool success = m_serialManager->openSerial(portName,115200);
    // qDebug()<<"打开结果："<<success;
    connect(ui->btnOpenPort,&QPushButton::clicked,this,[this](){
        if(m_serialManager->isOpen()){
            m_serialManager->closeSerial();
            ui->btnOpenPort->setText("打开串口");
            qDebug()<<"串口已关闭";
        }else{
            QString portName = ui->comboPort->currentText();
            bool success = m_serialManager->openSerial(portName,115200);
            if(success){
                ui->btnOpenPort->setText("关闭串口");
            }
            qDebug()<<"当前选择串口："<<portName<<"打开结果："<<success;
        }
    });

    connect(ui->btnRefreshPort,&QPushButton::clicked,this,[this](){
        const QStringList ports = m_serialManager->availablePorts();
        ui->comboPort->clear();
        ui->comboPort->addItems(ports);
        qDebug()<<"刷新后的串口："<<ports;
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
