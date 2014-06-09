#include "dragtool.hpp"

#include <QDebug>

DragTool::DragTool(QObject *parent) :
    Tool(parent)
{
    // Do nothing
}

void DragTool::mouseMoveEvent(ToolMouseMoveEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        view()->translate(event->dViewPos());
        qDebug() << event->dViewPos();
        event->accept();
    }
}

void DragTool::wheelEvent(ToolWheelEvent *event)
{
    qreal factor = 1.0 + event->angleDelta().y() / 1200.0;
    view()->scale(factor);
    event->accept();
}
