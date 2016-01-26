#include "kitchen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Kitchen w;
    w.show();

    return a.exec();
}
