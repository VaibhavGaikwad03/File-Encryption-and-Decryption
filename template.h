#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <QMainWindow>
class QWidget;
class QResizeEvent;
class QCloseEvent;

class Template : public QMainWindow
{
    Q_OBJECT;

public:
    Template(QMainWindow *parent = 0);

private:
    QWidget *background;

    // protected slots:
    //     void closeEvent(QCloseEvent *event);
};

#endif // TEMPLATE_H
