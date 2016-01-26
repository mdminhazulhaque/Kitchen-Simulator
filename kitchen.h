#ifndef KITCHEN_H
#define KITCHEN_H

#include <QMainWindow>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include "graphicsscene.h"

namespace Ui {
class Kitchen;
}

class Kitchen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Kitchen(QWidget *parent = 0);
    ~Kitchen();
    void moveToTable(int tableNum);
    void moveToPoint(QPointF targetPos);
    void wait();
    void disableButtons();
    void enableButtons();

private slots:
    void handleButton();

    void on_pushButton_Home_clicked();

    void on_pushButtonConnect_clicked();

    void on_pushButtonDisconnect_clicked();

private:
    bool left;
    Ui::Kitchen *ui;
    GraphicsScene scene;
    QSerialPort arduino;
};

#endif // KITCHEN_H
