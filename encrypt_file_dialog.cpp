#include "encrypt_file_dialog.h"
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
 
EncryptFileDialog::EncryptFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel;                      // creating label to display label on dialog
    enter_file_name_label->setText(tr("Enter file name: ")); // setting text in label

    file_name_textbox = new QLineEdit; // creating the textbox to get file name as input from user

    enter_password_label = new QLabel;                         // creating label to display label on dialog
    enter_password_label->setText(tr("Enter the password: ")); // setting text in label

    password_textbox = new QLineEdit;                   // creating the textbox to get password as input from user
    password_textbox->setEchoMode(QLineEdit::Password); // setting echo as "Password" to hide the password

    QVBoxLayout *vertical_layout = new QVBoxLayout; // creating a vertical layout
    // adding above all the four widgets to vertical layout
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);
    vertical_layout->addWidget(enter_password_label);
    vertical_layout->addWidget(password_textbox);

    encrypt_button = new QPushButton(tr("Encrypt"));                                 // creating an encrypt button
    connect(encrypt_button, SIGNAL(clicked(bool)), this, SLOT(encrypt_file_slot())); // connecting the encrypt button to the slot "encrypt_file_slot()"

    cancel_button = new QPushButton(tr("Cancel"));                      // creating cancel button
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close())); // connecting the cancel button to "close()" slot for closing the window

    QHBoxLayout *horizontal_layout = new QHBoxLayout; // creating horizontal layout
    // adding above two widgets to horizontal layout
    horizontal_layout->addWidget(encrypt_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout; // creating main layout
    // adding above two layout (vertical layout and horizontal layout) to main layout
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);               // resizing the dialog
    setLayout(main_layout);         // setting main layout as dialog layout
    setWindowTitle("Encrypt File"); // setting title of dialog
}

void EncryptFileDialog::encrypt_file_slot()
{
    // calling function to encrypt the file. the function accepts two parameters. first is file name and second is password
    // this function returns status that the encryption is successful or not
    int status = encrypt_data(file_name_textbox->text().toStdString(), password_textbox->text().toStdString());

    if (status == -1) // if user doesn't provide file name
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2) // if user doesn't provide password
        QMessageBox::warning(this, tr("Warning"), tr("Enter the password."));
    else if (status == -3) // if password is less than or greater than 8 characters
        QMessageBox::warning(this, tr("Warning"), tr("Password should contains strictly 8 characters."));
    else if (status == -4) // if file does not exists
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" does not exists!";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else if (status == -5) // if file already encrypted
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" already encrypted!";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else // success
    {
        string message = "Data from file \"" + file_name_textbox->text().toStdString() + "\" encrypted successfully.";

        QMessageBox::information(this, tr("Success"), tr(message.c_str()));
        this->close(); // after successful encryption dialog gets closed
        // clearing the input fields
        file_name_textbox->clear();
        password_textbox->clear();
    }
}
