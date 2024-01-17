#ifndef ENCRYPT_FILE_DIALOG_H
#define ENCRYPT_FILE_DIALOG_H

#include "enc_dec_logic.h"
#include <QDialog>
class QLabel;
class QLineEdit;
class QPushButton;

class EncryptFileDialog : public QDialog, public EncryptionDecryption
{
    Q_OBJECT;

public:
    EncryptFileDialog(QDialog *parent = 0);

private:
    QLabel *enter_file_name_label;
    QLabel *enter_password_label;
    QLineEdit *file_name_textbox;
    QLineEdit *password_textbox;
    QPushButton *encrypt_button;
    QPushButton *cancel_button;

private slots:
    void encrypt_file_slot();

    friend class MenuPage; // declaring MenuPage class as a friend so MenuPage can access our private members also
};

#endif // ENCRYPT_FILE_DIALOG_H
