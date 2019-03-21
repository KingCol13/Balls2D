#include "window.h"

#include <QPushButton>

Window::Window(QWidget *parent) : QWidget(parent){
    // Set size of the window
    setFixedSize(500, 500);

    // Create and position the button
<<<<<<< HEAD
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
=======
    m_button = new QPushButton("Hello World", this);
    m_button->setGeometry(10, 10, 80, 30);
    m_button->setCheckable(true);

    connect(m_button, SIGNAL (clicked(bool)), this, SLOT (slotButtonClicked(bool)));
}

void Window::slotButtonClicked(bool checked){
    if (checked) {
        m_button->setText("Checked");
    }
    else{
        m_button->setText("Hello World");

    }
    Window::update();
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    if(m_button->isChecked()){
        painter.setPen(Qt::blue);
        painter.drawEllipse(QPointF(250,250), 100, 100);
        painter.drawEllipse(QPointF(200,200), 10, 10);
        painter.drawEllipse(QPointF(300,200), 10, 10);
        painter.drawEllipse(QPointF(250,250), 10, 10);
        int start = 210 * 16;
        int span = 120 * 16;
        painter.drawChord(200, 300, 100, 25, start, span);
    }
    else{
        painter.eraseRect(150, 150, 200, 200);
    }
>>>>>>> c8d68fb3095c54fee9b9c61c3917cd002dfa2284
}
