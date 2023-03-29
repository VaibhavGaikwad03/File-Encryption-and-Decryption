#include "createpage.h"
#include "menupage.h"
#include "encdeclogic.h"
#include <QMessageBox>
#include <string>
using std::string;

CreatePage::CreatePage(QWidget* parent) : CreateDeleteTemplate(parent)
{
	m_createb = new QPushButton("Create File", this);
	m_createb->setGeometry(200, 200, 100, 30);
	connect(m_createb, &QPushButton::clicked, this, &CreatePage::create_event);
	connect(m_backb, &QPushButton::clicked, this, &CreatePage::back_event);
}

void CreatePage::create_event()
{
	int iRet = 0;
	EncryptionDecryption createfile;
	iRet = createfile.create_file(m_textbox->text().toStdString());
	
	if (iRet == -1)
		QMessageBox::warning(this, "Warning", "Please enter a file name.");
	else if (iRet == -2)
		QMessageBox::critical(this, tr("Error"), tr("File already exists."));
	else
	{
		QMessageBox::information(this, "Success", "File created successfully !");
		back_event();
	}
}

void CreatePage::back_event()
{
	MenuPage *menupage = new MenuPage();
	menupage->show();
	this->hide();
}

CreatePage::~CreatePage()
{
	
}