#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPointF>

#include <QThread>

#include "table.h"
#include <sys/unistd.h>

class GraphicsScene : public QGraphicsScene
{
public:
    GraphicsScene();
    void drawEnvironment();

    vector<Table> Tables;
    QGraphicsItem *robot1;
    QPointF tr;
    QPointF tl;
    QPointF br;
    QPointF bl;
};

#endif // GRAPHICSSCENE_H
