#include "application.hpp"

#include "project.hpp"

Application::Application(int argc, char** argv) :
    QGuiApplication(argc, argv),
    m_project(new Project(this))
{
    // Do nothing
}
