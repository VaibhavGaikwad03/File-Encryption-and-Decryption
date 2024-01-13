#ifndef DECRYPT_FILE_DIALOG_H
#define DECRYPT_FILE_DIALOG_H

#include <QDialog>
#include "enc_dec_logic.h"
class QLabel;
class QLineEdit;
class QPushButton;

class DecryptFileDialog : public QDialog, public EncryptionDecryption
{
    Q_OBJECT;

public:
    DecryptFileDialog(QDialog *parent = 0);

private:
    QLabel *enter_file_name_label;
    QLabel *enter_password_label;
    QLineEdit *file_name_textbox;
    QLineEdit *password_textbox;
    QPushButton *encrypt_button;
    QPushButton *cancel_button;

private slots:
    void decrypt_file_slot();

    friend class MenuPage;
};

#endif // DECRYPT_FILE_DIALOG_H
