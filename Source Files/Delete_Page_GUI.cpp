#include "deletepage.h"
#include "encdeclogic.h"
#include <QMessageBox>

DeletePage::DeletePage(QWidget* parent) : CreateDeleteTemplate(parent)
{
	m_deleteb = new QPushButton("Delete File", this);
	m_deleteb->setGeometry(200, 200, 100, 30);
	connect(m_deleteb, &QPushButton::clicked, this, &DeletePage::delete_event);
	connect(m_backb, &QPushButton::clicked, this, &DeletePage::back_event);
}

void DeletePage::delete_event()
{
	int iRet = 0;
	EncryptionDecryption deleteobj;
	string strFileName = m_textbox->text().toStdString();
	string strMessage = "Are you sure you want to delete \"" + strFileName + "\"?";

	if (strFileName == "")
		QMessageBox::warning(this, "Warning", "Please enter a file name.");

	else if (!deleteobj.is_exists(strFileName))
		QMessageBox::critical(this, tr("Error"), tr("File does not exists!"));

	else if (strFileName != "")
	{
		QMessageBox::StandardButton response;
		response = QMessageBox::question(this, "Confirmation", strMessage.c_str(), QMessageBox::Yes | QMessageBox::No);
		if (response == QMessageBox::Yes)
		{
			iRet = deleteobj.delete_file(strFileName);

			if (iRet == -3)
				QMessageBox::critical(this, tr("Error"), tr("We're unable to delete the file at this time. Please try again later."));
			if (iRet == 0)
			{
				QMessageBox::information(this, "Success", "File deleted successfully.");
				back_event();
			}
		}
	}
}

void DeletePage::back_event()
{
	menupage = new MenuPage();
	menupage->show();
	this->hide();
}

DeletePage::~DeletePage(){}