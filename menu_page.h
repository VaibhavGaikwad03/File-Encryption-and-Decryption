#ifndef MENU_PAGE_H
#define MENU_PAGE_H
#include <QWidget>
#include "template.h"
#include "create_file_dialog.h"
#include "write_file_dialog.h"
#include "encrypt_file_dialog.h"
#include "decrypt_file_dialog.h"
#include "delete_file_dialog.h"
class QPushButton;
class QLabel;
class Template;
class QCloseEvent;

class MenuPage : public Template
{
    Q_OBJECT;

public:
    MenuPage(Template *parent = 0);
    ~MenuPage();

private:
    // menu page contents
    QLabel *label;
    QPushButton *create_file_button;
    QPushButton *write_file_button;
    QPushButton *encrypt_file_button;
    QPushButton *decrypt_file_button;
    QPushButton *delete_file_button;
    QPushButton *exit_button;

    // dialogs
    CreateFileDialog *create_file_dialog;
    WriteFileDialog *write_file_dialog;
    EncryptFileDialog *encrypt_file_dialog;
    DecryptFileDialog *decrypt_file_dialog;
    DeleteFileDialog *delete_file_dialog;
private slots:
    void create_dialog();
    void write_dialog();
    void encrypt_dialog();
    void decrypt_dialog();
    void delete_dialog();
    void close();

private:
    void closeEvent(QCloseEvent *event);
};

#endif // MENU_PAGE_H
