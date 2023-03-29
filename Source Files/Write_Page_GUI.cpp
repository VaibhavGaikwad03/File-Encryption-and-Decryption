#include "writepage.h"
#include "encdeclogic.h"
#include <QMessageBox>
#include <string>
using std::string;

WritePage::WritePage(QWidget* parent) : Page(parent)
{
	string strLabel1 = "Enter the file name : ";
	m_label1 = new QLabel(strLabel1.c_str(), this);
	string strLabel2 = "Enter the data : ";
	m_label2 = new QLabel(strLabel2.c_str(), this);
	m_textbox1 = new QLineEdit(this);
	m_textbox2 = new QLineEdit(this);
	m_writefileb = new QPushButton("Write Data", this);
	m_backb = new QPushButton("Back", this);
	QFont font("Verdana", 10);
	QFontMetrics metrics(font);
	m_label1->setFont(font);
	m_label2->setFont(font);

	m_label1->setGeometry(200, 150, metrics.horizontalAdvance(strLabel1.c_str()), metrics.height());
	m_textbox1->setGeometry(200, 170, 210, 25);
	m_label2->setGeometry(200, 200, metrics.horizontalAdvance(strLabel2.c_str()), metrics.height());
	m_textbox2->setGeometry(200, 220, 210, 25);
	m_writefileb->setGeometry(200, 250, 100, 30);
	m_backb->setGeometry(310, 250, 100, 30);

	connect(m_writefileb, &QPushButton::clicked, this, &WritePage::write_event);
	connect(m_backb, &QPushButton::clicked, this, &WritePage::back_event);
}

void WritePage::write_event()
{
	int iRet = 0;
	EncryptionDecryption writefile;;

	iRet = writefile.write_file(m_textbox1->text().toStdString(), m_textbox2->text().toStdString(), 1);

	if (iRet == -1)
		QMessageBox::warning(this, "Warning", "Please enter a file name.");
	else if (iRet == -2)
		QMessageBox::warning(this, "Warning", "Please enter the data.");
	else if (iRet == -3)
		QMessageBox::critical(this, tr("Error"), tr("File does not exists !"));
	else if (iRet == -4)
		QMessageBox::critical(this, tr("Error"), tr("File could not be opened !"));
	else
	{
		QMessageBox::information(this, "Success", "Data has been successfully written to the file.");
		back_event();
	}
}

void WritePage::back_event()
{
	menupage = new MenuPage();
	menupage->show();
	this->hide();
}

WritePage::~WritePage()
{

}