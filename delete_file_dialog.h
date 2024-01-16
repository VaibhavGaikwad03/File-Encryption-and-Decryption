#ifndef DELETE_FILE_DIALOG_H
#define DELETE_FILE_DIALOG_H

#include <QDialog>
#include "enc_dec_logic.h"
class QLabel;
class QLineEdit;
class QPushButton;

class DeleteFileDialog : public QDialog, public EncryptionDecryption
{
    Q_OBJECT;

public:
    DeleteFileDialog(QDialog *parent = 0);

private:
    QLabel *enter_file_name_label;
    QLineEdit *file_name_textbox;
    QPushButton *delete_file_button;
    QPushButton *cancel_button;

private slots:
    void delete_file_slot();

    friend class MenuPage;
};

#endif // DELETE_FILE_DIALOG_H
