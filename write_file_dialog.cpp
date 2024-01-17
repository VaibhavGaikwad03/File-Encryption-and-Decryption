#include "write_file_dialog.h"
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

WriteFileDialog::WriteFileDialog(QDialog *parent) : QDialog(parent)
{
    // creating label to show enter file name on dialog
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText(tr("Enter file name: ")); // setting the text to show enter the file name

    // creating the textbox
    file_name_textbox = new QLineEdit;

    // QHBoxLayout *first_horizontal_layout = new QHBoxLayout;
    // first_horizontal_layout->addWidget(enter_file_name_label);
    // first_horizontal_layout->addWidget(file_name_textbox);

    // creating the label
    enter_file_data_label = new QLabel;
    enter_file_data_label->setText(tr("Enter data: ")); // setting text to show enter data on dialog

    // creating another textbox
    file_data_textbox = new QLineEdit;

    // creating vertical layout
    QVBoxLayout *vertical_layout = new QVBoxLayout;
    // all the below 4 widgets are added to vertical layout
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);
    vertical_layout->addWidget(enter_file_data_label);
    vertical_layout->addWidget(file_data_textbox);

    // QHBoxLayout *second_horizontal_layout = new QHBoxLayout;
    // second_horizontal_layout->addWidget(enter_file_data_label);
    // second_horizontal_layout->addWidget(file_data_textbox);

    // creating the button to write data into file
    write_data_button = new QPushButton("Write");
    connect(write_data_button, SIGNAL(clicked(bool)), this, SLOT(write_file_slot())); // connecting that write button to write_file_slot()

    // creating the button to close the dialog
    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close())); // connecting the cancel_button to the close() slot

    // creating
    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    // third_horizontal_layout->addStretch();
    horizontal_layout->addWidget(write_data_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    setLayout(main_layout);
    setWindowTitle("Write File");
    resize(300, 100);
}

void WriteFileDialog::write_file_slot()
{
    // write_file() funtion is used to write into a regular file. after calling that function the function returns status that it is successful or not.
    int status = write_file(file_name_textbox->text().toStdString(), file_data_textbox->text().toStdString(), 1);

    if (status == -1) // if file name is not provided by user
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2) // if data to be written is not provided by the user
        QMessageBox::warning(this, tr("Warning"), tr("Enter the data."));
    else if (status == -3) // if file does not exists
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" does not exists!";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else if (status == -4) // if there is an error while opening file
    {
        string message = "File \"" + file_name_textbox->text().toStdString() + "\" could not be opened!";
        QMessageBox::critical(this, tr("Error"), tr(message.c_str()));
    }
    else // success
    {
        string message = "Data has been successfully written to the file \"" + file_name_textbox->text().toStdString() + "\"";
        QMessageBox::information(this, tr("Success"), tr(message.c_str()));
        this->close();              // after writing into file close the dialog
        file_name_textbox->clear(); // clears file name from textbox
        file_data_textbox->clear(); // clreas file data from textbox
    }
}
