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
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText(tr("Enter file name: "));

    file_name_textbox = new QLineEdit;

    // QHBoxLayout *first_horizontal_layout = new QHBoxLayout;
    // first_horizontal_layout->addWidget(enter_file_name_label);
    // first_horizontal_layout->addWidget(file_name_textbox);

    enter_file_data_label = new QLabel;
    enter_file_data_label->setText(tr("Enter data: "));

    file_data_textbox = new QLineEdit;

    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);
    vertical_layout->addWidget(enter_file_data_label);
    vertical_layout->addWidget(file_data_textbox);

    // QHBoxLayout *second_horizontal_layout = new QHBoxLayout;
    // second_horizontal_layout->addWidget(enter_file_data_label);
    // second_horizontal_layout->addWidget(file_data_textbox);

    write_data_button = new QPushButton("Write");
    connect(write_data_button, SIGNAL(clicked(bool)), this, SLOT(write_file_slot()));

    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close()));

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
    file_name_textbox->setFocus();
    int status = write_file(file_name_textbox->text().toStdString(), file_data_textbox->text().toStdString(), 1);

    if (status == -1)
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2)
        QMessageBox::warning(this, tr("Warning"), tr("Enter the data."));
    else if (status == -3)
        QMessageBox::critical(this, tr("Error"), tr("File does not exists!"));
    else if (status == -4)
        QMessageBox::critical(this, tr("Error"), tr("File could not be opened!"));
    else
    {
        QMessageBox::information(this, tr("Success"), tr("Data has been successfully written to the file."));
        this->close();
        file_name_textbox->clear();
        file_data_textbox->clear();
    }
}
