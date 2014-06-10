#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QDockWidget>

/*!
 * \class MainWindow
 * \inmodule main
 *
 * \brief The main window of the application.
 */

// Properties

/*!
 * \property MainWindow::project
 * \brief The displayed Project.
 */

// Methods

/*!
 * Constructs MainWindow with parent widget \a parent
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_frameView(new AnimationFrameView),
    m_animationView(new AnimationView),
    m_layerView(new LayerView)
{
    ui->setupUi(this);

    setCentralWidget(frameView());

    QDockWidget *dockableAnimationView = new QDockWidget;
    dockableAnimationView->setWidget(animationView());
    this->addDockWidget(Qt::BottomDockWidgetArea, dockableAnimationView);

    QDockWidget *dockableLayerView = new QDockWidget;
    dockableLayerView->setWidget(layerView());
    this->addDockWidget(Qt::RightDockWidgetArea, dockableLayerView);
}

/*!
 * Destroys the widget.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setProject(Project *project)
{
    if (m_project == project)
        return;

    m_project = project;
    animationView()->setProject(project);
    frameView()->setFrame(project->frame(0));
    layerView()->setFrame(project->frame(0));
}

/*!
 * \fn MainWindow::frameView()
 * \brief Returns the AnimationFrameView child.
 */

/*!
 * \fn MainWindow::animationView()
 * \brief Returns the AnimationView child.
 */

/*!
 * \fn MainWindow::layerView()
 * \brief Returns the LayerView child.
 */
