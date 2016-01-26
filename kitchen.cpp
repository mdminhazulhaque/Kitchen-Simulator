#include "kitchen.h"
#include "ui_kitchen.h"

Kitchen::Kitchen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Kitchen)
{
    left = false;
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);

    connect(ui->pushButton_1, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_2, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_3, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_4, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_5, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_6, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_7, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_8, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_9, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_10, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_11, SIGNAL(clicked(bool)), this, SLOT(handleButton()));
    connect(ui->pushButton_12, SIGNAL(clicked(bool)), this, SLOT(handleButton()));

    disableButtons();
}

Kitchen::~Kitchen()
{
    delete ui;
}

void Kitchen::moveToTable(int tableNum)
{
    QPointF targetPos(scene.Tables.at(tableNum).px, scene.Tables.at(tableNum).py);
    moveToPoint(targetPos);

}

void Kitchen::moveToPoint(QPointF targetPos)
{
    QPointF currPos(scene.robot1->pos());

    int dx = targetPos.x() - currPos.x();
    int dy = targetPos.y() - currPos.y();

    dx -= 20;
    dy -= 20;

    //qDebug() << dx << dy;

    for(int i=0; i<abs(dy); i++)
    {
        int sign = dy/abs(dy);
        scene.robot1->moveBy(0, sign);
        wait();
    }

    for(int i=0; i<abs(dx); i++)
    {
        int sign = dx/abs(dx);
        scene.robot1->moveBy(sign, 0);
        wait();
    }

}

void Kitchen::wait()
{
    QThread::msleep(5);
    qApp->processEvents();
}

void Kitchen::disableButtons()
{
    ui->pushButton_1->setDisabled(true);
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_5->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);
    ui->pushButton_Home->setDisabled(true);
}

void Kitchen::enableButtons()
{
    ui->pushButton_1->setDisabled(false);
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(false);
    ui->pushButton_5->setDisabled(false);
    ui->pushButton_6->setDisabled(false);
    ui->pushButton_7->setDisabled(false);
    ui->pushButton_8->setDisabled(false);
    ui->pushButton_9->setDisabled(false);
    ui->pushButton_10->setDisabled(false);
    ui->pushButton_11->setDisabled(false);
    ui->pushButton_12->setDisabled(false);
    ui->pushButton_Home->setDisabled(false);
}

void Kitchen::handleButton()
{
    disableButtons();

    int tableID = sender()->objectName().remove("pushButton_").toInt();

    arduino.write(QString::number(tableID).toLatin1());
    qApp->processEvents();

    if(tableID >= 9 && !left)
    {
        left = true;
        moveToPoint(scene.bl);
        moveToPoint(scene.br);
    }

    moveToTable(tableID-1);

    enableButtons();
}

void Kitchen::on_pushButton_Home_clicked()
{
    moveToPoint(scene.tr);
    moveToPoint(scene.tl);
    left = false;
    arduino.write(QString::number(0).toLatin1());
}

void Kitchen::on_pushButtonConnect_clicked()
{
#ifdef Q_OS_LINUX
    arduino.setPortName("/dev/ttyUSB4");
#endif

#ifdef Q_OS_WIN
    arduino.setPortName("COM5");
#endif

    if(arduino.open(QSerialPort::WriteOnly))
    {
    arduino.setBaudRate(QSerialPort::Baud9600);
    arduino.setDataBits(QSerialPort::Data8);
    arduino.setParity(QSerialPort::NoParity);
    arduino.setStopBits(QSerialPort::OneStop);
    arduino.setFlowControl(QSerialPort::NoFlowControl);

    enableButtons();

    }
    else
    {
        qDebug() << "Could not open";
    }
}

void Kitchen::on_pushButtonDisconnect_clicked()
{
    arduino.close();
    disableButtons();
}
