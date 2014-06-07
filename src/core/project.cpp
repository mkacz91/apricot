#include "project.hpp"

#include <ApricotUtils>
#include "animationframe.hpp"

/*!
    \class Project
    \inmodule core

    \brief The root of Apricot data model.
 */

// Properties

/*!
    \property Project::size
    \brief The dimensions of the image
 */
/*!
    \property Project::width
    \brief The width of the image
 */
/*!
    \property Project::height
    \brief The height of the image
 */
/*!
    \property Project::frameCount
    \brief The number of animation frames
 */

// Signals

/*!
    \fn Project::framesChanged()
    \brief Emitted when animation frames are added, removed or change order.
 */
/*!
    \fn Project::layersChanged()
    \brief Emitted when layers are added, removed or change order.
 */

// Methods

/*!
 * \brief Constructs Project with parent object \a parent.
 */
Project::Project(QObject *parent) :
    QObject(parent)
{
    // Do nothing
}

void Project::setSize(const QSize &size)
{
    if (m_size != size) {
        m_size = size;
        emit sizeChanged();
    }
}

/*!
 * \fn Project::frame(int i)
 * \brief Returns AnimationFrame at index \a i.
 */

/*!
 * \brief Returns index of \a frame.
 */
int Project::indexOfFrame(const AnimationFrame *frame) const
{
    return frames.indexOf(const_cast<AnimationFrame *>(frame));
}

/*!
 * \brief Creates new AnimationFrame at index \a i and returns it.
 *
 * The new frame is a copy of the frame at \a i - 1 if it is present.
 */
AnimationFrame *Project::newFrame(int i)
{
    i = clamp(i, 0, frameCount());

    AnimationFrame *f = 0 < i
        ? new AnimationFrame(frame(i - 1), this)
        : new AnimationFrame(this); // Typically this should only happen in an empty project

    frames.insert(i, f);
    connect(f, SIGNAL(layersChanged()), this, SIGNAL(layersChanged()));

    emit framesChanged();
    if (f->layerCount() > 0)
        emit layersChanged();

    return f;
}

/*!
 * \fn Project::newFrame()
 * \brief Creats new AnimationFrame at the end of animation and returns it.
 *
 * The new frame is a copy of the last frame if present.
 */

/*!
 * Removes AnimationFrame at index \a i.
 */
void Project::removeFrame(int i)
{
    AnimationFrame *f = frames.takeAt(i);
    bool anyLayers = f->layerCount() > 0;
    delete f;

    emit framesChanged();
    if (anyLayers)
        emit layersChanged();
}