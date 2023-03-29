#include "createdeletetemplate.h"
#include <string>
using std::string;

CreateDeleteTemplate::CreateDeleteTemplate(QWidget* parent) : Page(parent)
{
	string strLabel = "Enter the file name : ";
	m_label = new QLabel(strLabel.c_str(), this);
	m_textbox = new QLineEdit(this);
	m_backb = new QPushButton("Back", this);
	QFont font("Verdana", 10);
	QFontMetrics metrics(font);
	m_label->setFont(font);

	m_label->setGeometry(200, 150, metrics.horizontalAdvance(strLabel.c_str()), metrics.height());
	m_textbox->setGeometry(200, 170, 210, 25);
	m_backb->setGeometry(310, 200, 100, 30);
}

CreateDeleteTemplate::~CreateDeleteTemplate()
{

}