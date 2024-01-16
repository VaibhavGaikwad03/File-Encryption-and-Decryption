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
#include <QHBoxLayout>
using std::string;

MenuPage::MenuPage(Template *parent) : Template(parent)
{
    string str_label = "Hello and welcome!\nTo proceed, please select one of the following options:";
    label = new QLabel(str_label.c_str(), this); // label created
    QFont font("Noto Serif", 13);                   // creating font object
    QFontMetrics metrics(font);
    label->setFont(font);                                                                         // setting the font
    label->setAlignment(Qt::AlignCenter);
    label->setGeometry(190, 130, metrics.horizontalAdvance(str_label.c_str()), metrics.height()*2); // setting label position
    label->setStyleSheet("color: white");                                                         // setting colour of label

    create_file_button = new QPushButton("Create File", this); // creating "Create File" button
    create_file_button->setGeometry(350, 220, 100, 30);        // setting button position
    connect(create_file_button, SIGNAL(clicked(bool)), this, SLOT(create_dialog()));
    // create_file_button->setStyleSheet("background-color: purple; border: 1px solid black;");

    write_file_button = new QPushButton("Write File", this); // creating "Write File" button
    write_file_button->setGeometry(550, 220, 100, 30);       // setting button position
    connect(write_file_button, SIGNAL(clicked(bool)), this, SLOT(write_dialog()));

    encrypt_file_button = new QPushButton("Encrypt File", this); // creating "Encrypt File" button
    encrypt_file_button->setGeometry(350, 290, 100, 30);         // setting button position
    connect(encrypt_file_button, SIGNAL(clicked(bool)), this, SLOT(encrypt_dialog()));

    decrypt_file_button = new QPushButton("Decrypt File", this); // creating "Decrypt File" button
    decrypt_file_button->setGeometry(550, 290, 100, 30);         // setting button position
    connect(decrypt_file_button, SIGNAL(clicked(bool)), this, SLOT(decrypt_dialog()));

    delete_file_button = new QPushButton("Delete File", this); // creating "Delete File" button
    delete_file_button->setGeometry(350, 360, 100, 30);        // setting button position
    connect(delete_file_button, SIGNAL(clicked(bool)), this, SLOT(delete_dialog()));

    exit_button = new QPushButton("Exit", this); // creating "Exit" button
    exit_button->setGeometry(550, 360, 100, 30); // setting button position
    connect(exit_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    // below steps are very important because if we couldn't set pointers to null. the behaviour of program is undefined
    create_file_dialog = nullptr;
    write_file_dialog = nullptr;
    encrypt_file_dialog = nullptr;
    decrypt_file_dialog = nullptr;
    delete_file_dialog = nullptr;
}

void MenuPage::close() // close() slot gets called when the user wants to close the window with cross icon or with the exit button
{
    Template::close(); // when the close() function of Template class gets called, internally the closeEvent() funtion gets invoked
    // when user closes the window it is mandatory the free the memory of the dialogs, if we dont freed the memory the dialogs memory doesn't gets free
}

void MenuPage::create_dialog() // when user clicks the button "Create File" the create_dialog() slot gets called.
{
    if (!create_file_dialog) // this check is required because if user clicks button multiple times the dialog gets created multiple times
        create_file_dialog = new CreateFileDialog;
    create_file_dialog->file_name_textbox->setFocus(); // for user simplicity we set the focus to file name textbox.
    create_file_dialog->show();                        // to show the dialog
}

void MenuPage::write_dialog() // when user clicks the button "Write File" the write_file() slot gets called.
{
    if (!write_file_dialog) // this check is required because if user clicks button multiple times the dialog gets created multiple times
        write_file_dialog = new WriteFileDialog;
    write_file_dialog->file_name_textbox->setFocus(); // for user simplicity we set the focus to file name textbox.
    write_file_dialog->show();                        // to show the dialog
}

void MenuPage::encrypt_dialog()
{
    if (!encrypt_file_dialog)
        encrypt_file_dialog = new EncryptFileDialog;
    encrypt_file_dialog->file_name_textbox->setFocus();
    encrypt_file_dialog->show();
}

void MenuPage::decrypt_dialog()
{
    if (!decrypt_file_dialog)
        decrypt_file_dialog = new DecryptFileDialog;
    decrypt_file_dialog->file_name_textbox->setFocus();
    decrypt_file_dialog->show();
}

void MenuPage::delete_dialog()
{
    if (!delete_file_dialog)
        delete_file_dialog = new DeleteFileDialog;
    delete_file_dialog->file_name_textbox->setFocus();
    delete_file_dialog->show();
}

void MenuPage::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton response;

    response = QMessageBox::question(this, "Confirmation", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);

    if (response == QMessageBox::Yes)
    {
        create_file_dialog->close();
        delete create_file_dialog;

        write_file_dialog->close();
        delete write_file_dialog;

        encrypt_file_dialog->close();
        delete encrypt_file_dialog;

        decrypt_file_dialog->close();
        delete decrypt_file_dialog;

        event->accept();
    }
    else
        event->ignore();
}

MenuPage::~MenuPage() {}
