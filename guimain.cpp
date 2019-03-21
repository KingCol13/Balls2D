#include <QApplication>
#include "window.h"
#include <QPainter>
#include "simulation.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

    Window window;
    window.show();

    return app.exec();
}
