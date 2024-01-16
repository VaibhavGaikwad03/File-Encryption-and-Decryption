#include "delete_file_dialog.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QMessageBox>
#include <string>
using std::string;

DeleteFileDialog::DeleteFileDialog(QDialog *parent) : QDialog(parent)
{
    enter_file_name_label = new QLabel;
    enter_file_name_label->setText(tr("Enter file name:"));

    file_name_textbox = new QLineEdit;

    QVBoxLayout *vertical_layout = new QVBoxLayout;
    vertical_layout->addWidget(enter_file_name_label);
    vertical_layout->addWidget(file_name_textbox);

    delete_file_button = new QPushButton("Delete");
    connect(delete_file_button, SIGNAL(clicked(bool)), this, SLOT(delete_file_slot()));

    cancel_button = new QPushButton("Cancel");
    connect(cancel_button, SIGNAL(clicked(bool)), this, SLOT(close()));

    QHBoxLayout *horizontal_layout = new QHBoxLayout;
    horizontal_layout->addWidget(delete_file_button);
    horizontal_layout->addWidget(cancel_button);

    QVBoxLayout *main_layout = new QVBoxLayout;
    main_layout->addLayout(vertical_layout);
    main_layout->addLayout(horizontal_layout);

    resize(300, 100);
    setLayout(main_layout);
    setWindowTitle("Delete File");
}

void DeleteFileDialog::delete_file_slot()
{
    int status = delete_file(file_name_textbox->text().toStdString());

    if (status == -1)
        QMessageBox::warning(this, tr("Warning"), tr("Enter the file name."));
    else if (status == -2)
        QMessageBox::critical(this, tr("Error"), tr("File does not exists!"));
    else if (status == -3)
        QMessageBox::critical(this, tr("Error"), tr("Can't delete file."));
    else
    {
        string str("\" deleted successfully.");
        QMessageBox::information(this, tr("Success"), tr(file_name_textbox->text().toStdString()+str));
        this->close();
        file_name_textbox->clear();
    }
}
