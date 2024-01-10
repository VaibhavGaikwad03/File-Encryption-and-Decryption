#ifndef MENU_PAGE_H
#define MENU_PAGE_H
#include <QWidget>
#include "template.h"
class QPushButton;
class QLabel;
class Template;

class MenuPage : public Template
{
    Q_OBJECT;
public:
    MenuPage(Template *parent = 0);

private:
    QLabel *label;
    QPushButton *create_file_button;
    QPushButton *write_file_button;
    QPushButton *encrypt_file_button;
    QPushButton *decrypt_file_button;
    QPushButton *delete_file_button;
    QPushButton *exit_button;
private slots:
    void close();
};

#endif // MENU_PAGE_H
