#include "window.h"

#include <QPushButton>

Window::Window(QWidget *parent) : QWidget(parent){
    // Set size of the window
    setFixedSize(500, 500);

    // Create and position the button
    m_button = new QPushButton("&Next Collision", this);
    m_button->setGeometry(10, 10, 100, 30);

    //Create and position render area
    rendArea = new renderArea(this);
    rendArea->setGeometry(10, 50, 400, 400);

    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::black);
    rendArea->setAutoFillBackground(true);
    rendArea->setPalette(pal);
    rendArea->show();

    connect(m_button, SIGNAL (clicked()), rendArea, SLOT (slotButtonClicked()));
}
