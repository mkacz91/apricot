#ifndef CORE_LAYER_HPP
#define CORE_LAYER_HPP

#include <QObject>

#include "Canvas.hpp"
#include "Painter.hpp"

class AnimationFrame;

class Layer : public QObject
{
    Q_OBJECT
    Q_PROPERTY(AnimationFrame *frame READ frame)
    Q_PROPERTY(const Canvas *canvas READ canvas)
    Q_PROPERTY(int width READ width)
    Q_PROPERTY(int height READ height)
    Q_PROPERTY(QSize size READ size)

public:
    explicit Layer(AnimationFrame *frame);
    Layer(const Layer *other, AnimationFrame *frame);

    AnimationFrame *frame() { return reinterpret_cast<AnimationFrame *>(parent()); }

    const Canvas *canvas() const { return &m_canvas; }

    int width() const { return m_canvas.width(); }
    int height() const { return m_canvas.height(); }
    QSize size() const { return m_canvas.size(); }

    Painter startPainting();

private:
    Canvas m_canvas;

    void setSize(const QSize &size);

private slots:
    void updateSize();
};

#endif // CORE_LAYER_HPP