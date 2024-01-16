#include "decrypt_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

DecryptFileDialog::DecryptFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel; // creating label to display label on dialog
    enter_file_name_label->setText(tr("Enter file name: "));    // setting text to the label

    file_name_textbox = new QLineEdit;  // creating the textbox to get file name as an input from user

    enter_password_label = new QLabel;  // creating another label to display on dialog
    enter_password_label->setText(tr("Enter the password: "));  // setting text to the label

    password_textbox = new QLineEdit;   // creating textbox to get password from user
    password_textbox->setEchoMode(QLineEdit::Password); // setting echo mode to "Password" for hiding the password

    QVBoxLayout *vertical_layout = new QVBoxLayout; // creating a vertical layout
    // adding widgets to the vertical layout
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);
    vertical_layout->addWidget(enter_password_label);
    vertical_layout->addWidget(password_textbox);

    encrypt_button = new QPushButton("Decrypt");    // creating a button
    connect(encrypt_button, SIGNAL(clicked(bool)), this, SLOT(decrypt_file_slot()));    // connecting the the button to the slot

    cancel_button = new QPushButton("Cancel");  // creating another button
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close())); // connecting the button to the slot

    QHBoxLayout *horizontal_layout = new QHBoxLayout;   // creating the horizontal layout
    // adding the widgets to horizontal layout
    horizontal_layout->addWidget(encrypt_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout; // creating main layout of our dialog
    // adding the above layouts (vertical layout and horizontal layout) to main layout
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);   // resizing the dialog
    setLayout(main_layout); // setting main_layout as Main Layout of dialog
    setWindowTitle("Decrypt File"); // setting window title
}

void DecryptFileDialog::decrypt_file_slot()
{
    // calling function to decrypt the file. it takes file name and password as input and returns the status.
    // that status states if the operation is successful or not.
    int status = decrypt_data(file_name_textbox->text().toStdString(), password_textbox->text().toStdString());

    if (status == -1)   // if name of file is not given by user
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2)  // if password is not given by user
        QMessageBox::warning(this, tr("Warning"), tr("Enter the password."));
    else if (status == -3)  // if file does not exists
        QMessageBox::critical(this, tr("Error"), tr("File does not exists!"));
    else if (status == -4)  // if file is already encrypted
        QMessageBox::critical(this, tr("Error"), tr("File already decrypted!"));
    else if (status == -5)  // if the password is incorrect
        QMessageBox::critical(this, tr("Error"), tr("Incorrect password. Please try again."));
    else    // success
    {
        QMessageBox::information(this, tr("Success"), tr("Data decrypted successfully."));
        this->close();  // close the dialog
        // clear the file name field and password field
        file_name_textbox->clear();
        password_textbox->clear();
    }
}
