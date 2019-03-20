#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>

class QPushButton;
class Window : public QWidget{
    Q_OBJECT
    public:
        explicit Window(QWidget *parent = 0);
        void paintEvent(QPaintEvent *);
    private slots:
        void slotButtonClicked(bool checked);
    private:
        QPushButton *m_button;
};

#endif // WINDOW_H
