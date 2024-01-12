#ifndef WRITE_FILE_DIALOG_H
#define WRITE_FILE_DIALOG_H

#include <QDialog>
#include "enc_dec_logic.h"
class QLabel;
class QLineEdit;
class QPushButton;

class WriteFileDialog : public QDialog, public EncryptionDecryption
{
    Q_OBJECT;

public:
    WriteFileDialog(QDialog *parent = 0);

private:
    QLabel *enter_file_name_label;
    QLabel *enter_file_data_label;
    QLineEdit *file_name_textbox;
    QLineEdit *file_data_textbox;
    QPushButton *write_data_button;
    QPushButton *cancel_button;
private slots:
    void write_file_slot();

    friend class MenuPage; // declaring MenuPage class as a friend so MenuPage can access our private members also
};

#endif // WRITE_FILE_DIALOG_H
