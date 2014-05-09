#ifndef CORE_CANVAS_PROVIDER_HPP
#define CORE_CANVAS_PROVIDER_HPP


#include <QQuickImageProvider>
#include <QDebug>


class Canvas;

class CanvasProvider : public QQuickImageProvider
{
public:
    CanvasProvider(const Canvas *canvas = nullptr);

    const Canvas *canvas() const { return m_canvas; }
    void setCanvas(const Canvas *canvas);

    virtual QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);

private:
    const Canvas *m_canvas;
};


#endif // CORE_CANVAS_PROVIDER_HPP
