#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
<<<<<<< HEAD


#include "renderarea.h"
=======
#include <QPaintEvent>
#include <QPainter>
>>>>>>> c8d68fb3095c54fee9b9c61c3917cd002dfa2284

class QPushButton;
class Window : public QWidget{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
<<<<<<< HEAD
        renderArea *rendArea;
=======
        void paintEvent(QPaintEvent *);
    private slots:
        void slotButtonClicked(bool checked);
>>>>>>> c8d68fb3095c54fee9b9c61c3917cd002dfa2284
    private:
        QPushButton *m_button;
};

#endif // WINDOW_H
