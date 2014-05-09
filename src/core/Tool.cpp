#include "Tool.hpp"

#include "ToolActionArea.hpp"
#include "ToolEvents.hpp"

Tool::Tool(QObject *parent) :
    QObject(parent)
{
    // Do nothing
}

void Tool::onActivated()
{
    // Do nothing
}

void Tool::onDeactivating()
{
    // Do nothing
}

void Tool::mousePressEvent(ToolMouseEvent *event)
{
    event->ignore();
}

void Tool::mouseReleaseEvent(ToolMouseEvent *event)
{
    event->ignore();
}

void Tool::mouseDoubleClickEvent(ToolMouseEvent *event)
{
    event->ignore();
}

void Tool::mouseHoverEvent(ToolMouseMoveEvent *event)
{
    event->ignore();
}

void Tool::mouseDragEvent(ToolMouseMoveEvent *event)
{
    event->ignore();
}

void Tool::mouseWheelEvent(ToolMouseWheelEvent *event)
{
    event->ignore();
}

QSGNode *Tool::updateActionAreaPaintNode(QSGNode *oldNode)
{
    return oldNode;
}

void Tool::setActionArea(ToolActionArea *actionArea)
{
    if (m_actionArea == actionArea)
        return;

    if (m_actionArea == nullptr)
    {
        m_actionArea = actionArea;
        emit actionAreaChanged();
        onActivated();
        emit activeChanged();
    }

    if (actionArea == nullptr)
    {
        emit deactivating();
        onDeactivating();
        m_actionArea = actionArea;
        emit actionAreaChanged();
        emit activeChanged();
        emit deactivated();
    }
}
