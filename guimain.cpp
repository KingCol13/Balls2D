#include <QApplication>
#include "window.h"
#include <QPainter>
#include "simulation.h"

int main(int argc, char **argv){
    QApplication app (argc, argv);

<<<<<<< HEAD
    //comment for testing.

=======
>>>>>>> 253b60bdeec293d6169c646891999708fcd7e88c
    Simulation sim(5, 1, 1, 10, 0.1);
    sim.ball_list[0].printData();
    sim.ball_list[1].printData();
    sim.run(10, 0, 0);
    sim.ball_list[0].printData();
    sim.ball_list[1].printData();

    Window window;
    window.show();



    return app.exec();
}
