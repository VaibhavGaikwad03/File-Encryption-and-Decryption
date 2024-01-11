#include "create_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

CreateFileDialog::CreateFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText("Enter file name: ");

    file_name_textbox = new QLineEdit;

    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);

    create_button = new QPushButton("Create");
    connect(create_button, SIGNAL(clicked(bool)), this, SLOT(create_file_slot()));

    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    // horizontal_layout->addStretch();
    horizontal_layout->addWidget(create_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);
    setLayout(main_layout);
    setWindowTitle("Create File");
}

void CreateFileDialog::create_file_slot()
{
    file_name_textbox->setFocus();
    int status = create_file(file_name_textbox->text().toStdString());

    if (status == -1)
        QMessageBox::warning(this, tr("Warning"), tr("Please enter the file name."));
    else if (status == -2)
        QMessageBox::critical(this, tr("Error"), tr("File already exists."));
    else
    {
        QMessageBox::information(this, tr("Success"), tr("File successfully created."));
        this->close();
        file_name_textbox->clear();
    }
}
