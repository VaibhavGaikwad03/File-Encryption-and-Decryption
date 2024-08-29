#include <QApplication>
#include "menu_page.h"
#include <QMainWindow>
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MenuPage menu_page;
    menu_page.show();

    return app.exec();
}
