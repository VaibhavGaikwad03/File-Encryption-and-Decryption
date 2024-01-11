#ifndef CREATE_FILE_DIALOG_H
#define CREATE_FILE_DIALOG_H

#include <QDialog>
#include "enc_dec_logic.h"
class QLabel;
class QLineEdit;
class QPushButton;

class CreateFileDialog : public QDialog, public EncryptionDecryption
{
    Q_OBJECT;

public:
    CreateFileDialog(QDialog *parent = 0);

private:
    QLabel *label;
    QLineEdit *textbox;
    QPushButton *create_button;
    QPushButton *cancel_button;

private slots:
    void create_file_slot();
    void cancel_slot();
};

#endif // CREATE_FILE_DIALOG_H
