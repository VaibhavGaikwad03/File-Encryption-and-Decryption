#include "decryptpage.h"
#include "encryptpage.h"
#include "encdeclogic.h"
#include <QMessageBox>
#include <string>
using std::string;

DecryptPage::DecryptPage(QWidget* parent) : EncDecTemplate(parent)
{
	m_decryptb = new QPushButton("Decrypt Data", this);
	m_decryptb->setGeometry(200, 250, 100, 30);
	connect(m_decryptb, &QPushButton::clicked, this, &DecryptPage::decrypt_event);
	connect(m_backb, &QPushButton::clicked, this, &DecryptPage::back_event);

}

void DecryptPage::decrypt_event()
{
	int iRet = 0;
	EncryptionDecryption decrypt;
	iRet = decrypt.decrypt_data(m_textbox1->text().toStdString(), m_passbox2->text().toStdString());

	if (iRet == -1)
		QMessageBox::warning(this, "Warning", "Please enter a file name.");
	else if (iRet == -2)
		QMessageBox::warning(this, "Warning", "Please enter the password.");
	else if (iRet == -3)
		QMessageBox::critical(this, tr("Error"), tr("File does not exists !"));
	else if (iRet == -4)
		QMessageBox::information(this, "File Decryption", "File has already been decrypted!");
	else if (iRet == -5)
		QMessageBox::critical(this, "Error", "Incorrect password. Please try again.");
	else
	{
		QMessageBox::information(this, "Success", "Data decrypted successfully.");
		back_event();
	}
}

void DecryptPage::back_event()
{
	menupage = new MenuPage();
	menupage->show();
	this->hide();
}

DecryptPage::~DecryptPage()
{

}