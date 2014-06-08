#include "animationframe.hpp"

#include "layer.hpp"
#include "project.hpp"

/*!
 * \class AnimationFrame
 * \inmodule model
 *
 * \brief A single frame of animation.
 *
 * May contain multiple layers.
 */

// Properties

/*!
 * \property AnimationFrame::project
 * \brief The parent Project.
 *
 * It is also the QObject parent of the frame.
 */

/*!
 * \property AnimationFrame::size
 * \brief The dimensins of the frame
 */

/*!
 * \property AnimationFrame::width
 * \brief The width of the frame.
 */

/*!
 * \property AnimationFrame::height
 * \brief The height of the frame.
 */

/*!
 * \property AnimationFrame::layerCount
 * \brief The number of layers
 */

// Signals

/*!
 * \fn AnimationFrame::layersChanged()
 * \brief Emitted when layers are added, removed or change order.
 */

// Methods

/*!
 * \brief Constructs a frame with parent project \a project.
 *
 * The \a project is also the parent object of the newly created AnimationFrame.
 */
AnimationFrame::AnimationFrame(Project *project) :
    QObject(project)
{
    // Do nothing
}

/*!
 * Constructs a copy of \a \other with parent project \a project.
 *
 * Newly created AnimationFrame receives a copy of all layers of \a other. The \a project is also
 * the parent object of the frame.
*/
AnimationFrame::AnimationFrame(const AnimationFrame *other, Project *project) :
    QObject(project)
{
    foreach (const Layer *layer, other->m_layers)
        this->m_layers.append(new Layer(layer, this));
}

const QSize &AnimationFrame::size() const
{
    // This has to be implemented here because of dependency loop that would arise if
    // animationframe.hpp included project.hpp.
    return project()->size();
}

/*!
 * \fn AnimationFrame::layers() const
 * \brief Returns a list of layers that make up the animation frame.
 */

/*!
 * \fn AnimationFrame::layer(int i)
 * \brief Returns layer at index \a i.
 *
 * The topmost layer has index 0.
 */

/*!
 * \fn AnimationFrame::layer(int i) const
 * \brief Returns immutable layer at index \a i.
 *
 * The topmost layer has index 0.
 */

/*!
 * \brief Creates a new layer at index \a i and returns it.
 */
Layer *AnimationFrame::newLayer(int i)
{
    Layer *l = new Layer(this);
    m_layers.insert(i, l);
    emit layersChanged();
    return l;
}

/*!
 * \fn AnimationFrame::newLayer()
 * \brief Creates a new layer above all existing ones and returns it.
 */

/*!
 * \brief Moves layer from position \a from to position \a to.
 *
 * This affects the indices of layers between \a from and \a to inclusive, as the other layers are
 * moved accordingly.
 */
void AnimationFrame::moveLayer(int from, int to)
{
    if (from != to) {
        m_layers.move(from, to);
        emit layersChanged();
    }
}

/*!
 * Removes layer at index \a i.
 */
void AnimationFrame::removeLayer(int i)
{
    delete m_layers.takeAt(i);
    emit layersChanged();
}
