#include "create_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

CreateFileDialog::CreateFileDialog(QDialog *parent) : QDialog(parent)
{
    // creating label to show the message
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText("Enter file name: ");

    // creating textbox to get file name as input from user
    file_name_textbox = new QLineEdit;

    // creating vertical layout to align widgets vertically
    QVBoxLayout *vertical_layout = new QVBoxLayout;
    // both the widgets added to vertical_layout
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);

    // creating button to create a file
    create_button = new QPushButton("Create");
    connect(create_button, SIGNAL(clicked(bool)), this, SLOT(create_file_slot())); // connecting the button to "create_file_slot()"

    // creating button to close the create file dialog
    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close())); // connecting the button to "close()" slot

    // creating the horizontal layout to align widgets horizontally
    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    // horizontal_layout->addStretch();
    // both the widgets added to horizontal_layout
    horizontal_layout->addWidget(create_button);
    horizontal_layout->addWidget(cancel_button);

    // creating main layout for the create file dialog
    QVBoxLayout *main_layout = new QVBoxLayout;
    // both the vertical and horizontal layouts added to the main layout
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);              // resize the size of dialog
    setLayout(main_layout);        // setting main layout as the layout of create file dialog
    setWindowTitle("Create File"); // setting the title of window (dialog)
}

void CreateFileDialog::create_file_slot()
{
    file_name_textbox->setFocus();                                     // setting focus to file name text box
    int status = create_file(file_name_textbox->text().toStdString()); // calls create_file() function and returns the status that the file creation is successfull or not.

    if (status == -1) // if user doesn't provide file name
        QMessageBox::warning(this, tr("Warning"), tr("Please enter the file name."));
    else if (status == -2) // if file is already exists
        QMessageBox::critical(this, tr("Error"), tr("File already exists."));
    else // if file gets created successfully
    {
        QMessageBox::information(this, tr("Success"), tr("File successfully created."));
        this->close();              // after successful creation of file close the dialog
        file_name_textbox->clear(); // and clear the text from textbox
    }
}
