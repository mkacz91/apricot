#ifndef VIEW_TOOL_HPP
#define VIEW_TOOL_HPP

#include <QObject>

#include "toolevents.hpp"

class ToolActionArea;

class Tool : public QObject
{
    Q_OBJECT
    Q_PROPERTY(ToolActionArea *actionArea READ actionArea NOTIFY actionAreaChanged)
    Q_PROPERTY(bool active READ active NOTIFY activeChanged)

public:
    explicit Tool(QObject *parent = nullptr);

    ToolActionArea *actionArea() const { return m_actionArea; }

    bool active() const { return m_actionArea != nullptr; }

signals:
    void actionAreaChanged();
    void activeChanged();
    void deactivating();

protected:
    virtual void onActivated();
    virtual void onDeactivating();

    virtual void mousePressEvent(ToolMouseEvent *event);
    virtual void mouseReleaseEvent(ToolMouseEvent *event);
    virtual void mouseDoubleClickEvent(ToolMouseEvent *event);
    virtual void mouseMoveEvent(ToolMouseMoveEvent *event);
    virtual void wheelEvent(ToolWheelEvent *event);
    virtual void keyPressEvent(ToolKeyEvent *event);
    virtual void keyReleaseEvent(ToolKeyEvent *event);

private:
    ToolActionArea *m_actionArea;

    void setActionArea(ToolActionArea *actionArea);

    friend class ToolActionArea;
};


#endif // VIEW_TOOL_HPP
