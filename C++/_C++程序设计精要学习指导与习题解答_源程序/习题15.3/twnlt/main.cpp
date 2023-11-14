#pragma once

#include "twnlt.h"
#include <QtWidgets/QApplication>
#include <qdesktopwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //////////////////////////////////////////////////////////////////
    twnlt w;
    w.show();
    /////////////////////////////////////////////////////////////////
    //QGraphicsScene* scene = new QGraphicsScene;
    //scene->addLine(10, 10, 150, 300);
    //QGraphicsView* view = new QGraphicsView(scene);
    //view->resize(500, 500);
    //view->setWindowTitle("Graphics View");
    //view->show();
    /////////////////////////////////////////////////////////////////


    return a.exec();
}
