#include "create_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>

CreateFileDialog::CreateFileDialog(QDialog *parent) : QDialog(parent)
{
    label = new QLabel;
    label->setText("Enter file name: ");

    textbox = new QLineEdit;

    QHBoxLayout *upper_horizontal_layout = new QHBoxLayout;
    upper_horizontal_layout->addWidget(label);
    upper_horizontal_layout->addWidget(textbox);

    create_button = new QPushButton("Create");
    connect(create_button, SIGNAL(clicked(bool)), this, SLOT(create_file_slot()));

    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(cancel_slot()));

    QHBoxLayout *lower_horizontal_layout = new QHBoxLayout;
    lower_horizontal_layout->addStretch();
    lower_horizontal_layout->addWidget(create_button);
    lower_horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(upper_horizontal_layout);
    main_layout->addLayout(lower_horizontal_layout);

    setLayout(main_layout);
    setWindowTitle("Create File");
}

void CreateFileDialog::create_file_slot()
{
    int status = create_file(textbox->text().toStdString());

    if (status == -1)
        QMessageBox::warning(this, tr("Warning"), tr("Please enter the file name."));
    else if(status == -2)
        QMessageBox::warning(this,tr("Warning"), tr("File already exists."));
    else
        QMessageBox::information(this, tr("Success"), tr("File successfully created."));
}

void CreateFileDialog::cancel_slot()
{
    this->close();
}
