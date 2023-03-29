#include "encdectemplate.h"
#include <string>
using std::string;

EncDecTemplate::EncDecTemplate(QWidget* parent) : Page(parent)
{
	string strLabel1 = "Enter the file name : ";
	m_label1 = new QLabel(strLabel1.c_str(), this);
	string strLabel2 = "Enter the password : ";
	m_label2 = new QLabel(strLabel2.c_str(), this);
	m_textbox1 = new QLineEdit(this);
	m_passbox2 = new QLineEdit(this);
	m_passbox2->setEchoMode(QLineEdit::Password);
	m_backb = new QPushButton("Back", this);
	QFont font("Verdana", 10);
	QFontMetrics metrics(font);
	m_label1->setFont(font);
	m_label2->setFont(font);

	m_label1->setGeometry(200, 150, metrics.horizontalAdvance(strLabel1.c_str()), metrics.height());
	m_textbox1->setGeometry(200, 170, 210, 25);
	m_label2->setGeometry(200, 200, metrics.horizontalAdvance(strLabel2.c_str()), metrics.height());
	m_passbox2->setGeometry(200, 220, 210, 25);
	m_backb->setGeometry(310, 250, 100, 30);
}

EncDecTemplate::~EncDecTemplate() {}