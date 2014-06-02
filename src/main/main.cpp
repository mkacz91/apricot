#include <QDebug>

#include "Application.hpp"
#include "MainWindow.hpp"
#include "ApricotCore.hpp"
#include "ApricotTools.hpp"

int main(int argc, char *argv[])
{
    Application application(argc, argv);
    MainWindow mainWindow;

    application.project()->setSize(918, 655);
    Layer *layer = application.project()->newFrame()->newLayer();
    Painter painter = layer->startPainting();
    painter.load(":/images/isocastle.png");

    ToolActionArea actionArea;
    DragTool dragTool;
    actionArea.setTool(&dragTool);
    actionArea.setCanvas(layer->canvas());

    mainWindow.setCentralWidget(&actionArea);
    mainWindow.show();

    return application.exec();
}
