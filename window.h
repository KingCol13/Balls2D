#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>


#include "renderarea.h"

class QPushButton;
class Window : public QWidget{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        renderArea *rendArea;
    private:
        QPushButton *m_button;
};

#endif // WINDOW_H
