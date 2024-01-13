#include "decrypt_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

DecryptFileDialog::DecryptFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText(tr("Enter file name: "));

    file_name_textbox = new QLineEdit;

    enter_password_label = new QLabel;
    enter_password_label->setText(tr("Enter the password: "));

    password_textbox = new QLineEdit;
    password_textbox->setEchoMode(QLineEdit::Password);

    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);
    vertical_layout->addWidget(enter_password_label);
    vertical_layout->addWidget(password_textbox);

    encrypt_button = new QPushButton("Decrypt");
    connect(encrypt_button, SIGNAL(clicked(bool)), this, SLOT(decrypt_file_slot()));

    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    horizontal_layout->addWidget(encrypt_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);
    setLayout(main_layout);
    setWindowTitle("Decrypt File");
}

void DecryptFileDialog::decrypt_file_slot()
{
    int status = decrypt_data(file_name_textbox->text().toStdString(), password_textbox->text().toStdString());

    if (status == -1)
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2)
        QMessageBox::warning(this, tr("Warning"), tr("Enter the password."));
    else if (status == -3)
        QMessageBox::critical(this, tr("Error"), tr("File does not exists!"));
    else if (status == -4)
        QMessageBox::critical(this, tr("Error"), tr("File already decrypted!"));
    else if (status == -5)
        QMessageBox::critical(this, tr("Error"), tr("Incorrect password. Please try again."));
    else
    {
        QMessageBox::information(this, tr("Success"), tr("Data decrypted successfully."));
        this->close();
        file_name_textbox->clear();
        password_textbox->clear();
    }
}
