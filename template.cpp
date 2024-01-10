#include "template.h"
#include <QWidget>
#include <QResizeEvent>
#include <QSizePolicy>
#include <QMessageBox>

Template::Template(QMainWindow *parent) : QMainWindow(parent)
{
    setFixedSize(1000, 600);    // setting fixed size of parent window
    setWindowTitle("File Encryption and Decryption");   // setting title to window
    setWindowIcon(QIcon(":/res/images/icon.png"));  // setting icon to window
    background = new QWidget(this); // creating widget for setting backgroud image
    setCentralWidget(background);   // setting widget at center
    // background->setStyleSheet("background-image: url(:/res/images/background.jpg);");
    background->setStyleSheet("background-image: url(:/res/images/background.jpg);"
                              "background-position: center; /* Center the image */"
                              "background-repeat: no-repeat; /* Prevent image repetition */"
                              );    // setting stylesheet like background image, position of backgroud image,
        //  repeate image (to prevent from repeat image when user maximize the window)
}

void Template::closeEvent(QCloseEvent *event)
{
    QMessageBox::StandardButton response;
    response = QMessageBox::question(this, "Confirmation", "Are you sure you want to exit?", QMessageBox::Yes | QMessageBox::No);
    if (response == QMessageBox::Yes)
        event->accept();
    else
        event->ignore();
}
