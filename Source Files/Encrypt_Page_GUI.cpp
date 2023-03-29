#include "encryptpage.h"
#include "encdeclogic.h"
#include <QMessageBox>
#include <string>
using std::string;

EncryptPage::EncryptPage(QWidget* parent) : EncDecTemplate(parent)
{
	m_encryptb = new QPushButton("Encrypt Data", this);
	m_encryptb->setGeometry(200, 250, 100, 30);

	connect(m_encryptb, &QPushButton::clicked, this, &EncryptPage::encrypt_event);
	connect(m_backb, &QPushButton::clicked, this, &EncryptPage::back_event);
}

void EncryptPage::encrypt_event()
{
	int iRet = 0;
	EncryptionDecryption encrypt;
	iRet = encrypt.encrypt_data(m_textbox1->text().toStdString(), m_passbox2->text().toStdString());

	if (iRet == -1)
		QMessageBox::warning(this, "Warning", "Please enter a file name.");
	else if (iRet == -2)
		QMessageBox::warning(this, "Warning", "Please enter the password.");
	else if (iRet == -3)
		QMessageBox::warning(this, "Warning", "The password should contain strictly eight characters.");
	else if (iRet == -4)
		QMessageBox::critical(this, tr("Error"), tr("File does not exists !"));
	else if (iRet == -5)
		QMessageBox::critical(this, tr("Error"), tr("File already encrypted !"));
	else
	{
		QMessageBox::information(this, "Success", "Data encrypted successfully.");
		back_event();
	}
}

void EncryptPage::back_event()
{
	menupage = new MenuPage();
	menupage->show();
	this->hide();
}

EncryptPage::~EncryptPage()
{

}