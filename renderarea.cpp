#include "renderarea.h"

renderArea::renderArea(QWidget *parent) : QWidget(parent)
{
    sim = new Simulation(2, 1, 1, 10, 1);

}

void renderArea::slotButtonClicked(){
    sim->next_collision();
    sim->printData();
    fflush(stdout);
    renderArea::update();
}

void renderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPointF point;
    double *pos;
    double rad;

    point.setX(0);
    point.setY(0);
    rad = sim->ball_list[sim->num_balls-1].getRadius();

    int side = qMin(width(), height());

    //painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width() / 2, height() / 2);
    painter.scale(side / (2*rad), side / (2*rad));

    painter.setPen(QPen(Qt::blue, 0));

    painter.drawEllipse(point, rad, rad);


    painter.setPen(QPen(Qt::red, 0));
    painter.setBrush(Qt::red);
    for(int i=0; i<sim->num_balls-1; i++){
        pos = sim->ball_list[i].getPos();
        rad = sim->ball_list[i].getRadius();
        point.setX(pos[0]);
        point.setY(pos[1]);
        painter.drawEllipse(point, rad, rad);
    }


}
