#ifndef CREATE_FILE_PAGE_H
#define CREATE_FILE_PAGE_H

#include "template.h"
class QLineEdit;
class QPushButton;
class QLabel;

class CreateFile : public Template
{
    Q_OBJECT;

public:
    CreateFile(QMainWindow *parent = 0);

private:
    QLabel *label;
    QLineEdit *textbox;
    QPushButton *create_file_button;
    QPushButton *back_button;
};

#endif // CREATE_FILE_PAGE_H
