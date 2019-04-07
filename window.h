#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QThread>


#include "renderarea.h"
#include "worker.h"

class QPushButton;
class Window : public QWidget{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        renderArea *rendArea;
    private:
        QPushButton *col_button;
        QPushButton *play_button;
        Worker *worker;
    private slots:
        void slotPlayButtonClicked(bool checked);
};

#endif // WINDOW_H
