#include "window.h"

#include <QPushButton>

Window::Window(QWidget *parent) : QWidget(parent){
    // Set size of the window
    setFixedSize(500, 500);

    // Create and position the button
    col_button = new QPushButton("&Next Collision", this);
    col_button->setGeometry(10, 10, 100, 30);

    play_button = new QPushButton("&Play", this);
    play_button->setGeometry(110, 10, 100, 30);
    play_button->setCheckable(true);

    //Create and position render area
    rendArea = new renderArea(this);
    rendArea->setGeometry(10, 50, 400, 400);

    QPalette pal = palette();

    // set black background
    pal.setColor(QPalette::Background, Qt::black);
    rendArea->setAutoFillBackground(true);
    rendArea->setPalette(pal);
    rendArea->show();

    connect(col_button, SIGNAL (clicked()), rendArea, SLOT (slotColButtonClicked()));


    worker = new Worker(rendArea, rendArea->sim);
    QThread* thread = new QThread;
    worker->moveToThread(thread);
    connect(thread, SIGNAL (started()), worker, SLOT (process()));

    connect(play_button, SIGNAL (clicked(bool)), rendArea, SLOT (slotPlayButtonClicked(bool)));
    connect(play_button, SIGNAL (clicked()), worker, SLOT(process()));
    connect(play_button, SIGNAL (clicked(bool)), this, SLOT(slotPlayButtonClicked(bool)));
    thread->start();
}

void Window::slotPlayButtonClicked(bool checked){
    printf("this ran\n");
    if(checked){
        play_button->setText("&Pause");
    }
    else{
        play_button->setText("&Play");
    }
}
