#include "graphicsscene.h"

GraphicsScene::GraphicsScene()
{
    tr = QPointF(369, 38);
    tl = QPointF(130, 38);
    br = QPointF(369, 426);
    bl = QPointF(130, 426);

    // left
    Tables.push_back(Table(13, 127, 80, 40, 130, 146));
    Tables.push_back(Table(13, 201, 80, 40, 130, 220));
    Tables.push_back(Table(13, 276, 80, 40, 130, 295));
    Tables.push_back(Table(13, 350, 80, 40, 130, 369));

    // center
    Tables.push_back(Table(170, 127, 160, 40, 130, 146));
    Tables.push_back(Table(170, 201, 160, 40, 130, 220));
    Tables.push_back(Table(170, 276, 160, 40, 130, 295));
    Tables.push_back(Table(170, 350, 160, 40, 130, 369));

    // right
    Tables.push_back(Table(402, 350, 80, 40, 369, 369));
    Tables.push_back(Table(402, 276, 80, 40, 369, 295));
    Tables.push_back(Table(402, 201, 80, 40, 369, 220));
    Tables.push_back(Table(402, 127, 80, 40, 369, 146));

    drawEnvironment();
}

void GraphicsScene::drawEnvironment()
{
    for(unsigned int i=0; i<Tables.size(); i++)
    {
        Table& t = Tables[i];
        addRect(t.x, t.y, t.w, t.h, QPen(), QBrush(Qt::lightGray));
        QGraphicsTextItem *txt = addText(QString::number(i+1));
        txt->setPos(t.x+10, t.y+10);

        //addLine(t.px, t.py-5, t.px, t.py+5);
        addLine(t.px-5, t.py, t.px+5, t.py);
    }

    addLine(tl.x(), tl.y(), tr.x(), tr.y(), QPen(Qt::red));
    addLine(tr.x(), tr.y(), br.x(), br.y(), QPen(Qt::red));
    addLine(br.x(), br.y(), bl.x(), bl.y(), QPen(Qt::red));
    addLine(bl.x(), bl.y(), tl.x(), tl.y(), QPen(Qt::red));

    robot1 = addRect(0, 0, 40, 40, QPen(), QBrush(Qt::green));
    robot1->setPos(tl.x()-20, tl.y()-20);
}
