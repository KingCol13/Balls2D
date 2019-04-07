#include "renderarea.h"

renderArea::renderArea(QWidget *parent) : QWidget(parent)
{
    sim = new Simulation(100, 1, 0.1, 10, 1);

}

void renderArea::slotColButtonClicked(){
    sim->next_collision();
    sim->printData();
    fflush(stdout);
    renderArea::update();
}

void renderArea::slotPlayButtonClicked(bool checked){
    if(checked){
        playing=true;
    }
    else{
        playing=false;
    }
}


void renderArea::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPointF point;
    double *pos;
    double *cont_pos;
    double rad;
    double cont_rad;

    //get container size
    cont_rad = -sim->ball_list[sim->num_balls-1].getRadius();

    //get container position
    cont_pos = sim->ball_list[sim->num_balls-1].getPos();

    //get side for making square
    int side = qMin(width(), height());

    //set the necessary transformations
    painter.translate(width() / 2, height() / 2 );
    painter.scale(side / (2*cont_rad), side / (2*cont_rad));

    //draw container ellipse
    point.setX(0);
    point.setY(0);
    painter.setPen(QPen(Qt::blue, 0));
    painter.drawEllipse(point, cont_rad, cont_rad);


    painter.setPen(QPen(Qt::red, 0));
    painter.setBrush(Qt::red);
    for(int i=0; i<sim->num_balls-1; i++){
        pos = sim->ball_list[i].getPos();
        rad = sim->ball_list[i].getRadius();
        point.setX(pos[0] - cont_pos[0]);
        point.setY(pos[1] - cont_pos[1]);
        painter.drawEllipse(point, rad, rad);
    }

    //draw collision number
    point.setX(-0.95*cont_rad);
    point.setY(-0.9*cont_rad);
    QFont font("Times", 1, -1, false);
    painter.setFont(font);
    const QString text = QString::number(sim->col_number);
    painter.drawText(point, text);

}
