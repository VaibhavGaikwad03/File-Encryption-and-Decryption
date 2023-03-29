#include "page.h"

Page::Page(QWidget *parent) : QWidget(parent)
{
	setFixedSize(600, 500);
	setWindowTitle("File Encryption and Decryption Application");
	setWindowIcon(QIcon("pgp-encryption-hero.jpg"));
	QPixmap piximage("pgp-encryption-hero.jpg");
	m_imagelabel = new QLabel(this);
	m_imagelabel->setPixmap(piximage);
	m_imagelabel->setGeometry(20, 20, 53, 53);
}