#include "menu_page.h"
#include "template.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFont>
#include <string>
#include <QMessageBox>
#include <QCloseEvent>
#include <QLineEdit>
using std::string;

MenuPage::MenuPage(Template *parent) : Template(parent)
{
    string str_label = "Hello Welcome, Select one of the following options:";
    label = new QLabel(str_label.c_str(), this); // label created
    QFont font("Verdana", 13);                   // creating font object
    QFontMetrics metrics(font);
    label->setFont(font);                                                                         // setting the font
    label->setGeometry(250, 150, metrics.horizontalAdvance(str_label.c_str()), metrics.height()); // setting label position
    label->setStyleSheet("color: white");                                                         // setting colour of label

    create_file_button = new QPushButton("Create File", this); // creating "Create File" button
    create_file_button->setGeometry(291, 200, 100, 30);        // setting button position
    connect(create_file_button, SIGNAL(clicked(bool)), this, SLOT(create_dialog()));
    // create_file_button->setStyleSheet("background-color: purple; border: 1px solid black;");

    write_file_button = new QPushButton("Write File", this); // creating "Write File" button
    write_file_button->setGeometry(541, 200, 100, 30);       // setting button position
    connect(write_file_button, SIGNAL(clicked(bool)), this, SLOT(write_dialog()));

    encrypt_file_button = new QPushButton("Encrypt File", this); // creating "Encrypt File" button
    encrypt_file_button->setGeometry(291, 270, 100, 30);         // setting button position

    decrypt_file_button = new QPushButton("Decrypt File", this); // creating "Decrypt File" button
    decrypt_file_button->setGeometry(541, 270, 100, 30);         // setting button position

    delete_file_button = new QPushButton("Delete File", this); // creating "Delete File" button
    delete_file_button->setGeometry(291, 340, 100, 30);        // setting button position

    exit_button = new QPushButton("Exit", this); // creating "Exit" button
    exit_button->setGeometry(541, 340, 100, 30); // setting button position
    connect(exit_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    create_file_dialog = nullptr;
    write_file_dialog = nullptr;
}

void MenuPage::close()
{
    Template::close();
    delete create_file_dialog;
    delete write_file_dialog;
}

void MenuPage::create_dialog()
{
    if (!create_file_dialog)
        create_file_dialog = new CreateFileDialog;
    create_file_dialog->show();
}

void MenuPage::write_dialog()
{
    if (!write_file_dialog)
        write_file_dialog = new WriteFileDialog;
    write_file_dialog->file_name_textbox->setFocus();
    write_file_dialog->show();
}

MenuPage::~MenuPage() {}
