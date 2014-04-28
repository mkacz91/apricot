#include "canvasprovider.hpp"

#include <QDebug>
#include <QBitmap>

#include "canvas.hpp"

CanvasProvider::CanvasProvider(const Canvas *canvas) :
    QQuickImageProvider(Pixmap),
    m_canvas(canvas)
{
    // Do nothing
}

void CanvasProvider::setCanvas(const Canvas *canvas)
{
    m_canvas = canvas;
}

QPixmap CanvasProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    if (id != "canvas")
        return QPixmap();

    QPixmap pixmap = (m_canvas != 0) ? m_canvas->toPixmap() : QBitmap(1, 1);
    if (size != 0)
        *size = pixmap.size();
    return requestedSize.isValid() ? pixmap.scaled(requestedSize) : pixmap;
}
