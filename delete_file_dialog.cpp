#include "delete_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <string>

DeleteFileDialog::DeleteFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel;                     // creating label to display on dialog
    enter_file_name_label->setText(tr("Enter file name:")); // setting text to the label

    file_name_textbox = new QLineEdit; // creating textbox to get input from user

    QVBoxLayout *vertical_layout = new QVBoxLayout; // creating vertical layout
    // adding widgets to vertical layout
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);

    delete_file_button = new QPushButton("Delete");                                     // creating a button
    connect(delete_file_button, SIGNAL(clicked(bool)), this, SLOT(delete_file_slot())); // connecting the button to the slot

    cancel_button = new QPushButton("Cancel");                          // creating another button
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close())); // connecting the button to the slot

    QHBoxLayout *horizontal_layout = new QHBoxLayout; // creating the horizontal layout
    // adding widgets to horizontal layout
    horizontal_layout->addWidget(delete_file_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout; // creating main layout
    // adding above vertical layout and horizontal layout to the main layout
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);              // resizing the size
    setLayout(main_layout);        // setting layout
    setWindowTitle("Delete File"); // setting the title of dialog window
}

void DeleteFileDialog::delete_file_slot()
{
    // calling delete file function to delete a regular file
    // after calling it returns the status that indicates the operation is successful or not
    int status = delete_file(file_name_textbox->text().toStdString());

    if (status == -1) // if file name is not entered by user
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2) // if file does not exists
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" does not exists!";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else if (status == -3) // if unable to delete a file
    {
        string message = "Can't delete file \"" + file_name_textbox->text().toStdString() + "\".";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else // success
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" deleted successfully.";
        QMessageBox::information(this, tr("Success"), tr(message.c_str()));
        this->close();              // closing the dialog window
        file_name_textbox->clear(); // clearing the text
    }
}
